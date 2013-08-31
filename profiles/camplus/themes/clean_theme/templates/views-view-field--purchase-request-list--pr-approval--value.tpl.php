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

	//是否canceled？ flag
	// $node = $row->_field_data['nid']['entity'];
$g = flag_get_counts($content_type='node',$row->nid, $reset = FALSE);
$show = TRUE;
if(isset($g['cancel']) && $g['cancel']) $show = FALSE;
  global $user;
  if(in_array('head', $user->roles)) {
	  $department_nid = $row->field_field_budget_items[0]['raw']['entity']->field_parents_department[LANGUAGE_NONE][0]['target_id'];
	  //header变更，如果head没有group admin权限，不可以rate
	  $og_roles = og_get_user_roles($group_type='node', $gid=$department_nid, $uid = NULL, $include = FALSE);
	  if(in_array('panel head', $og_roles) && $show) {
	      // $show_flag = FALSE;
	  	print $output;
	  }
	}else{
		print $output;
	}
  //end header变更
?>
