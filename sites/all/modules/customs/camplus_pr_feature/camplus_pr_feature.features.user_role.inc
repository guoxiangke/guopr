<?php
/**
 * @file
 * camplus_pr_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function camplus_pr_feature_user_default_roles() {
  $roles = array();

  // Exported role: financial manager.
  $roles['financial manager'] = array(
    'name' => 'financial manager',
    'weight' => 5,
    'machine_name' => 'financial_manager',
  );

  // Exported role: panel head.
  $roles['panel head'] = array(
    'name' => 'panel head',
    'weight' => 4,
    'machine_name' => 'panel_head',
  );

  // Exported role: school board.
  $roles['school board'] = array(
    'name' => 'school board',
    'weight' => 9,
    'machine_name' => 'school_board',
  );

  return $roles;
}
