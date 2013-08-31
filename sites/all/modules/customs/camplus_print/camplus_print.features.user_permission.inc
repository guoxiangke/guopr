<?php
/**
 * @file
 * camplus_print.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function camplus_print_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print',
  );

  return $permissions;
}
