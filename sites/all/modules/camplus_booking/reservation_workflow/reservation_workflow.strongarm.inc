<?php
/**
 * @file
 * reservation_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function reservation_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_extensions_change_state_button_label';
  $strongarm->value = '[workflow:workflow-new-state-name]';
  $export['workflow_extensions_change_state_button_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_extensions_change_state_form_title';
  $strongarm->value = '<none>';
  $export['workflow_extensions_change_state_form_title'] = $strongarm;

  return $export;
}
