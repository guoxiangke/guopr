<?php
/**
 * @file
 * camplus_default.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function camplus_default_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
