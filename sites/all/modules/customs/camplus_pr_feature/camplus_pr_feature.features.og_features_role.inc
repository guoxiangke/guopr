<?php
/**
 * @file
 * camplus_pr_feature.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function camplus_pr_feature_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:school_department:panel head'.
  $roles['node:school_department:panel head'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'school_department',
    'name' => 'panel head',
  );

  return $roles;
}
