<?php
/**
 * @file
 * camplus_pr_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function camplus_pr_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function camplus_pr_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function camplus_pr_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Cancel".
  $flags['cancel'] = array(
    'entity_type' => 'node',
    'title' => 'Cancel',
    'global' => 0,
    'types' => array(
      0 => 'purchase_request',
    ),
    'flag_short' => 'Cancel PR',
    'flag_long' => '',
    'flag_message' => 'Cancelled',
    'unflag_short' => 'Cancelled',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Canceled',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => 'own',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure to Cancel? This action CANNOT undo!',
    'unflag_confirmation' => 'You CANNOT unCancel!',
    'module' => 'camplus_pr_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Paid".
  $flags['paid'] = array(
    'entity_type' => 'node',
    'title' => 'Paid',
    'global' => 1,
    'types' => array(
      0 => 'purchase_request',
    ),
    'flag_short' => 'Complete',
    'flag_long' => '',
    'flag_message' => 'Completed',
    'unflag_short' => 'NotCompleted',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Completed',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'camplus_pr_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Lock".
  $flags['pr_lock'] = array(
    'entity_type' => 'node',
    'title' => 'Lock',
    'global' => 1,
    'types' => array(
      0 => 'purchase_request',
    ),
    'flag_short' => 'Lock',
    'flag_long' => '',
    'flag_message' => 'Flagged',
    'unflag_short' => 'UnLock',
    'unflag_long' => '',
    'unflag_message' => 'Unflagged',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'camplus_pr_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function camplus_pr_feature_node_info() {
  $items = array(
    'budget_item' => array(
      'name' => t('Budget Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'purchase_request' => array(
      'name' => t('Purchase Request'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Item Requested to Purchase'),
      'help' => '',
    ),
    'school_department' => array(
      'name' => t('School Department'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
