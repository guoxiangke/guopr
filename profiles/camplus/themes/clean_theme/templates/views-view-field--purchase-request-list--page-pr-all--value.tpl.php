 <?php
  // 1|Draft
  // 2|Locked
  // 3|Pending
  // 4|Approved
  // 5|Rejected
  // 6|Completed
  // 7|Cancelled
 // dpm($row);
 $pr_node = node_load($row->nid);
 $show = array('4','6');
 if(in_array($pr_node->field_pr_status[LANGUAGE_NONE][0]['value'], $show)) {
 	print $output;
 }