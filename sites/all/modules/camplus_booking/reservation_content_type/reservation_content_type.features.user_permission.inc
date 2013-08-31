<?php
/**
 * @file
 * reservation_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function reservation_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access workflow summary views'.
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workflow_views',
  );

  // Exported permission: 'create reservation content'.
  $permissions['create reservation content'] = array(
    'name' => 'create reservation content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create resource content'.
  $permissions['create resource content'] = array(
    'name' => 'create resource content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any resource content'.
  $permissions['delete any resource content'] = array(
    'name' => 'delete any resource content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own reservation content'.
  $permissions['delete own reservation content'] = array(
    'name' => 'delete own reservation content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own resource content'.
  $permissions['delete own resource content'] = array(
    'name' => 'delete own resource content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any resource content'.
  $permissions['edit any resource content'] = array(
    'name' => 'edit any resource content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own reservation content'.
  $permissions['edit own reservation content'] = array(
    'name' => 'edit own reservation content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own resource content'.
  $permissions['edit own resource content'] = array(
    'name' => 'edit own resource content',
    'roles' => array(
      'booking_mananger' => 'booking_mananger',
    ),
    'module' => 'node',
  );

  return $permissions;
}
