<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
  // 1|Draft
  // 2|Locked
  // 3|Pending
  // 4|Approved
  // 5|Rejected
  // 6|Completed
  // 7|Cancelled
 // dpm($row);
 $pr_node = node_load($row->nid);
 $show = array('1','5','6','7');
 if(in_array($pr_node->field_pr_status[LANGUAGE_NONE][0]['value'], $show)) {
 }else {
 	print $output;
 }
?>
