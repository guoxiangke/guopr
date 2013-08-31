<?php
/**
 * @file
 * reservation_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function reservation_workflow_user_default_roles() {
  $roles = array();

  // Exported role: booking_mananger.
  $roles['booking_mananger'] = array(
    'name' => 'booking_mananger',
    'weight' => 4,
    'machine_name' => 'booking_mananger',
  );

  return $roles;
}
