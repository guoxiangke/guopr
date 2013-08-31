<?php
/**
 * @file
 * default_clean_theme.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function default_clean_theme_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access textsize content'.
  $permissions['access textsize content'] = array(
    'name' => 'access textsize content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'textsize',
  );

  return $permissions;
}
