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
if($field->field_alias == 'votingapi_cache_node_value') {
	$node = node_load($row->nid);
	$show_flag = TRUE;
	$flags = flag_get_counts('node', $node->nid, $reset = FALSE);
	if(isset($flags['paid']) && $flags['paid']) {
		$show_flag = FALSE;
	}
    $widgets = rate_get_active_widgets('node', 'purchase_request');
    foreach ($widgets as $widget_id => $widget) {
      //没有权限时，清楚rate
      $widget->id = $widget_id;
      //一旦审核通过，所有审批部门角色不可更改即 not show rate.
      if($widget->name == 'approve') {
        $approve_status = _rate_pr_check_permissions($node,$widget);

        $widget_name = 'rate_' . $widget->name;
        if(!$approve_status['permit_flag'] || !$show_flag) {
          // 根据PR节点的总额确定which审批流程
          // 在上一个审批流程没有确定前 其他后续
          $output = '--';
        }
        break;
      }
    }
}

?>
<?php print $output; ?>