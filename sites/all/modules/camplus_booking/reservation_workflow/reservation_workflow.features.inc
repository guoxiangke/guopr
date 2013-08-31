<?php
/**
 * @file
 * reservation_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function reservation_workflow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_workflow_default_workflows().
 */
function reservation_workflow_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Booking Approval
  $workflows['Booking Approval'] = array(
    'name' => 'Booking Approval',
    'tab_roles' => '150186561,53849329',
    'options' => 'a:4:{s:16:"comment_log_node";s:1:"0";s:15:"comment_log_tab";s:1:"1";s:13:"name_as_title";s:1:"1";s:12:"watchdog_log";s:1:"1";}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Booking Approval',
      ),
      1 => array(
        'state' => 'Pending',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Booking Approval',
      ),
      2 => array(
        'state' => 'Approved',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Booking Approval',
      ),
      3 => array(
        'state' => 'Rejected',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Booking Approval',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => 'Pending',
      ),
      1 => array(
        'roles' => 'administrator,teacher,booking_mananger',
        'state' => 'Pending',
        'target_state' => 'Approved',
      ),
      2 => array(
        'roles' => 'administrator,teacher,booking_mananger',
        'state' => 'Pending',
        'target_state' => 'Rejected',
      ),
      3 => array(
        'roles' => 'administrator',
        'state' => 'Approved',
        'target_state' => 'Pending',
      ),
      4 => array(
        'roles' => 'administrator',
        'state' => 'Approved',
        'target_state' => 'Rejected',
      ),
      5 => array(
        'roles' => 'administrator',
        'state' => 'Rejected',
        'target_state' => 'Pending',
      ),
      6 => array(
        'roles' => 'administrator',
        'state' => 'Rejected',
        'target_state' => 'Approved',
      ),
    ),
    'node_types' => array(
      0 => 'reservation',
    ),
  );

  return $workflows;
}
