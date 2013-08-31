<?php
/**
 * @file
 * reservation_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function reservation_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_to_ask_for_approval'] = entity_import('rules_config', '{ "rules_send_email_to_ask_for_approval" : {
      "LABEL" : "Send email to ask for approval",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "room" : { "label" : "Room", "type" : "node" },
        "reservation" : { "label" : "Reservation", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "room" ], "field" : "field_approver" } },
              { "NOT data_is_empty" : { "data" : [ "room:field-approver" ] } },
              { "entity_has_field" : { "entity" : [ "room" ], "field" : "field_need_approval" } },
              { "data_is" : { "data" : [ "room:field-need-approval" ], "value" : 1 } },
              { "node_is_of_type" : {
                  "node" : [ "room" ],
                  "type" : { "value" : { "resource" : "resource" } }
                }
              }
            ],
            "DO" : [
              { "drupal_message" : { "message" : "Email had been sent to [room:field-approver:mail]" } },
              { "mail" : {
                  "to" : [ "room:field-approver:mail" ],
                  "subject" : "New pending approval of [room:title] ([reservation:title])",
                  "message" : "\\u003Ca href=\\u0022[site:url]\\/workflow\\/pending\\u0022\\u003ELink to approval\\u003C\\/a\\u003E\\r\\nLink to reservation: [reservation:url]\\r\\nLink to room: [room:url]",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "Send email rule"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "room" ]
    }
  }');
  $items['rules_send_message_to_approver'] = entity_import('rules_config', '{ "rules_send_message_to_approver" : {
      "LABEL" : "Send message to approver",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Approval" ],
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_transition" : {
            "node" : [ "node" ],
            "old_state" : { "value" : { "ANY" : "ANY" } },
            "new_state" : { "value" : { "2" : "2" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "reservation" : "reservation" } }
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-room" ] },
            "ITEM" : { "list_room" : "Current room" },
            "DO" : [
              { "component_rules_send_email_to_ask_for_approval" : {
                  "USING" : { "room" : [ "list-room" ], "reservation" : [ "node" ] },
                  "PROVIDE" : { "room" : { "room" : "Room" } }
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_skip_waiting_for_approval'] = entity_import('rules_config', '{ "rules_skip_waiting_for_approval" : {
      "LABEL" : "Skip waiting-for-approval",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "reservation_workflow" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "reservation" : "reservation" } }
          }
        }
      ],
      "DO" : [ { "reservation_workflow_skip_approval" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
