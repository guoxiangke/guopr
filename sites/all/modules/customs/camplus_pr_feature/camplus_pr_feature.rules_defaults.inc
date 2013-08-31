<?php
/**
 * @file
 * camplus_pr_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function camplus_pr_feature_default_rules_configuration() {
  $items = array();
  $items['rules_add_members_to_department'] = entity_import('rules_config', '{ "rules_add_members_to_department" : {
      "LABEL" : "Add members to Department",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "purchase request" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "school_department" : "school_department" } }
          }
        },
        { "og_entity_is_group" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:members" ] },
            "ITEM" : { "group_members" : "group member" },
            "DO" : [
              { "og_unsubscribe_user" : { "user" : [ "group-members" ], "group" : [ "node" ] } }
            ]
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-member" ] },
            "ITEM" : { "member_list" : "member list" },
            "DO" : [
              { "og_subcribe_user" : { "user" : [ "member-list" ], "group" : [ "node" ] } }
            ]
          }
        },
        { "og_subcribe_user" : { "user" : [ "node:field-panel-head" ], "group" : [ "node" ] } },
        { "og_grant_og_role" : {
            "account" : [ "node:field-panel-head" ],
            "group" : [ "node" ],
            "roles" : { "value" : { "7" : "7" } }
          }
        },
        { "drupal_message" : { "message" : "[node:field-panel-head] becomes the Panel Head of Department \\u0022[node:title]\\u0022" } }
      ]
    }
  }');
  $items['rules_pr_cancelled_status'] = entity_import('rules_config', '{ "rules_pr_cancelled_status" : {
      "LABEL" : "PR Cancelled status",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "pr" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_cancel" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-pr-status" ], "value" : "7" } },
        { "drupal_message" : { "message" : "rule \\u0022PR Cancelled status\\u0022" } }
      ]
    }
  }');
  $items['rules_pr_locked'] = entity_import('rules_config', '{ "rules_pr_locked" : {
      "LABEL" : "PR Locked",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "pr" ],
      "REQUIRES" : [ "rules", "rate_pr", "flag" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        },
        { "rate_pr_condition_lock" : { "new_answer" : [ "node" ] } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-pr-status" ], "value" : "2" } },
        { "flag_flagnode" : {
            "flag" : "pr_lock",
            "node" : [ "node" ],
            "permission_check" : 1,
            "flagging_user" : [ "node:author" ]
          }
        }
      ]
    }
  }');
  $items['rules_pr_locked_email'] = entity_import('rules_config', '{ "rules_pr_locked_email" : {
      "LABEL" : "PR Locked Email",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "pr" ],
      "REQUIRES" : [ "rules", "rate_pr" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        },
        { "rate_pr_condition_email" : { "new_answer" : [ "node" ] } }
      ],
      "DO" : [ { "rate_pr_action_email" : { "new_answer" : [ "node" ] } } ]
    }
  }');
  $items['rules_pr_paid_status'] = entity_import('rules_config', '{ "rules_pr_paid_status" : {
      "LABEL" : "PR Paid status",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "pr" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_paid" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-pr-status" ], "value" : "6" } }
      ]
    }
  }');
  $items['rules_pr_reference'] = entity_import('rules_config', '{ "rules_pr_reference" : {
      "LABEL" : "PR reference",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "purchase request" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "node:field-pr-reference" ],
            "value" : "[node:field_pr_reference][node:nid]"
          }
        }
      ]
    }
  }');
  $items['rules_pr_unlocked'] = entity_import('rules_config', '{ "rules_pr_unlocked" : {
      "LABEL" : "PR UnLocked",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "pr" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_unflagged_pr_lock" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-pr-status" ], "value" : "3" } }
      ]
    }
  }');
  $items['rules_send_email_to_head'] = entity_import('rules_config', '{ "rules_send_email_to_head" : {
      "LABEL" : "Send email to Head",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "purchase request" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_budget_items" } },
        { "entity_has_field" : {
            "entity" : [ "node:field-budget-items:0" ],
            "field" : "field_parents_department"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-budget-items:0:field-parents-department" ],
            "field" : "field_panel_head"
          }
        },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        },
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "data_is" : { "data" : [ "node:field-pr-status" ], "value" : "3" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [
              "node:field-budget-items:0:field-parents-department:field-panel-head:mail"
            ],
            "subject" : "Purchase Request of [node:title] submitted by [node:author]",
            "message" : "Dear [node:field-budget-items:0:field-parents-department:field-panel-head]\\r\\n\\r\\n[node:author] had submitted a Purchase Request of [node:title], please go to [site:url]pr\\/my-approval for approval.\\r\\n\\r\\nThe current status of this Purchase Request is [node:field-pr-status].\\r\\n\\r\\nThank you for your attention.\\r\\n\\r\\nCamplus Purchase Request System",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Purchase Request of [node:title]",
            "message" : "Dear [node:author],\\r\\n\\r\\nYour Purchase Request of [node:title] has been submitted, the current status is [node:field-pr-status].\\r\\n\\r\\nPlease to to view your Purchase Request at [node:url]\\r\\n\\r\\nThank you.\\r\\n\\r\\nCamplus Purchase Request System",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "The Purchase Request of [node:title] has been submitted for Approval Process" } }
      ]
    }
  }');
  $items['rules_send_email_when_pr_approved'] = entity_import('rules_config', '{ "rules_send_email_when_pr_approved" : {
      "LABEL" : "Send email when PR approved",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "purchase request" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-pr-status" ], "value" : "4" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Your Purchase Request of [node:title] Approved",
            "message" : "Dear [node:author],\\r\\n\\r\\nYour Purchase Request of [node:title] has been approved! You can now go to order the item your requested to purchase.\\r\\n\\r\\nPlease noted that you need to print the Purchase Request Form in the system and Quotation files (if any) when you receive the true copy of Invoice. Then you should hand all these files to office.\\r\\n\\r\\nThank you.\\r\\n\\r\\nCamplus Purchase Request System",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_mail_next_approval_role'] = entity_import('rules_config', '{ "rules_send_mail_next_approval_role" : {
      "LABEL" : "Send mail to next approval role",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "purchase request" ],
      "REQUIRES" : [ "rules", "voting_rules", "views_bulk_operations" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "purchase_request" : "purchase_request" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-pr-status" ], "value" : "3" } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "1" } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_id_list" : {
            "USING" : {
              "view" : "list_of_users_of_specific_role|default",
              "args" : "[node:field_pr_rid_after]"
            },
            "PROVIDE" : { "entity_id_list" : { "entity_id_list" : "A list of entity ids" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-id-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "user", "id" : [ "list-item" ] },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
                }
              },
              { "mail" : {
                  "to" : [ "entity-fetched:mail" ],
                  "subject" : "Pending approval for the Purchase Request of [node:title]",
                  "message" : "Dear [entity-fetched:name],\\r\\n\\r\\nPlease go to [node:url] for approval of the Purchase Request of [node:title] submitted by [node:author].\\r\\n\\r\\nThank you.",
                  "language" : [ "" ]
                }
              },
              { "drupal_message" : { "message" : "You have approved the Purchase Request. Email has been sent to user(s) in next approval stage." } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_subscribe_children_groups'] = entity_import('rules_config', '{ "rules_subscribe_children_groups" : {
      "LABEL" : "subscribe children groups",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "og" ],
      "REQUIRES" : [ "rules", "rate_pr", "og" ],
      "ON" : [ "og_user_insert" ],
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "og-membership:group" ],
            "type" : { "value" : { "school_department" : "school_department" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "rete_pr_og_rules_add_entitys_to_group" : { "entity" : [ "account" ], "group" : [ "group" ] } }
      ]
    }
  }');
  return $items;
}
