<?php
/**
 * return a form setting of PR roles involved.
 */
function camplus_pr_roles_involved_settings_form($form, &$form_state) {
  $roles = user_roles(TRUE, 'camplus purchase request approvable');
  $count = 0;
  $camplus_pr_approvable_role_involved = variable_get('camplus_pr_approvable_role_involved','');
  
	foreach ($roles as $key => $role_name) {
		if (in_array($role_name, array('administrator'))) continue;

    $default_value = 0;
    if($camplus_pr_approvable_role_involved){
      if(isset($camplus_pr_approvable_role_involved[$role_name]))
      $default_value =  $camplus_pr_approvable_role_involved[$role_name];
    }
    $form['involved'][$role_name] =  array(
        '#type' => 'checkbox',
        '#title' => $role_name,
        '#default_value' => $default_value,
      );
    $count++;
	}
  $form['warning_info'] = array('#markup' => t('Note: The following settings are critical, please make sure you know what your are doing! <br> If you need to remove any role invloved in the Approval Process, please <strong> first uncheck the whole column in the '.l('Approval Workflow','admin/config/camplus/pr_settings/pr_approve_settings').' for that cancelled role(s)
</strong>'),
    '#weight'=>-10,'#prefix' => '<div class="messages warning">',
    '#suffix' => '</div>');

  if(!$count) {
  	$form['empty_text'] = array('#markup' => t('There is no role invloved in the Approval Process, please add roles with "Approval for Purchase Request" Permission'));
  	return $form;
  }
	// Add the buttons.
	$form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );
	return  $form;
}

function camplus_pr_roles_involved_settings_form_submit($form, &$form_state) {
  $roles = user_roles(TRUE, 'camplus purchase request approvable');

  foreach ($form_state['values'] as $role_name => $value) {
    if(in_array($role_name, $roles)) {
      $camplus_pr_approvable_role_involved[$role_name] = $value;
    }
  }
  variable_set('camplus_pr_approvable_role_involved',$camplus_pr_approvable_role_involved);
}

function camplus_pr_roles_weight_settings_form($form, &$form_state) {
  $roles = user_roles(TRUE, 'camplus purchase request approvable');
  $camplus_pr_approvable_role_involved = variable_get('camplus_pr_approvable_role_involved');
  // dpm($camplus_pr_approvable_role_involved,'camplus_pr_approvable_role_involved');
  $count = 0;
  $camplus_pr_approvable_role_weight = variable_get('camplus_pr_approvable_role_weight','');

  foreach ($roles as $key => $role_name) {
    $default_value = 'NULL';
    if (in_array($role_name, array('administrator'))) continue;
    if(!$camplus_pr_approvable_role_involved[$role_name]) continue;
      if($camplus_pr_approvable_role_weight){
        if(isset($camplus_pr_approvable_role_weight[$role_name]))
        $default_value =  $camplus_pr_approvable_role_weight[$role_name];
      }
    $form[$role_name]['approvable_role_weight'][$role_name] = array(
      '#type' => 'textfield',
      '#size' => 20, 
      '#default_value' => $default_value,
    );
    $count++;
  }

  if(!$count) {
    $form['empty_text'] = array('#markup' => t('There is no role invloved in the Approval Process, please add roles with "Approval for Purchase Request" Permission'));
    return $form;
  }
  // Add the buttons.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );
  return  $form;
}

function camplus_pr_roles_weight_settings_form_submit($form, &$form_state) {
  $roles = user_roles(TRUE, 'camplus purchase request approvable');
  foreach ($form_state['values'] as $role_name => $value) {
    if(in_array($role_name, $roles)) {
      $camplus_pr_approvable_role_weight[$role_name] = $value;
    }
  }
  variable_set('camplus_pr_approvable_role_weight', $camplus_pr_approvable_role_weight);
}
/**
 * Returns HTML
 */
function theme_camplus_pr_roles_weight_settings_form($variables) {
  $form = $variables['form'];
  // $errors = form_get_errors() != FALSE ? form_get_errors() : array();
  $rows = array();
  foreach (element_children($form) as $role_name) { //dpm($key);
    if (isset($form[$role_name]['approvable_role_weight'])) {
      $row = array();
      $row[] = $role_name;
      $row[] = drupal_render($form[$role_name]['approvable_role_weight']);
      $row = array('data' => $row);
      $rows[] = $row;
    }
  }
  if (empty($rows)) {
    $rows[] = array(array('data' => t('no any role'), 'colspan' => '2'));
  }
	$rows[] = array(array('data' => drupal_render($form['name']) .drupal_render($form['add']), 'colspan' => 4));
  $header = array(t('Role'), t('Weight for approvable role'));
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'approvable_role')));
  $output .= drupal_render_children($form);
  $warning = '<div class="messages warning">'.t('Note: The minimum weight MUST be assigned to Department specific role, e.g. set 1 for Department Head role
.').'</div>';
  return $warning . $output;
}

function camplus_pr_range_settings_form() {
 $i=0;
 $range = variable_get('camplus_pr_settings_range', '5');
 $range_settings = variable_get('camplus_pr_range_settings', ''); 
 $camplus_pr_file_settings = variable_get('camplus_pr_file_settings');
 while($i<$range){
  if(!isset($range_settings[$i])) {
    $range_settings[$i]["begin"] = '';
    $range_settings[$i]["end"] = '';
    $camplus_pr_file_settings["pr_quofile_require_$i"] = 0;
    $camplus_pr_file_settings["pr_quo_file_no_$i"] = 0;
    $camplus_pr_file_settings["pr_ref_file_require_$i"] =0;
  }
    $form[$i]['range']["pr_range_begin_$i"] = array(
      '#type' => 'textfield',
      '#default_value' =>$range_settings[$i]["begin"],
      '#prefix' => 'HK$',
      '#size' => 20, 
    );
    $form[$i]['range']["pr_range_end_$i"] = array(
      '#type' => 'textfield',
      '#default_value' =>$range_settings[$i]["end"],
      '#prefix' => 'HK$',
      '#size' => 20, 
    );
    $form[$i]["pr_quofile_require_$i"] = array(
      '#type' => 'checkbox',
      '#default_value' => $camplus_pr_file_settings["pr_quofile_require_$i"],
    );
    $form[$i]["pr_quo_file_no_$i"] = array(
      '#type' => 'textfield',
      '#default_value' => $camplus_pr_file_settings["pr_quo_file_no_$i"],
      '#size' => 2, 
    );
    $form[$i]["pr_ref_file_require_$i"] = array(
      '#type' => 'checkbox',
      '#default_value' => $camplus_pr_file_settings["pr_ref_file_require_$i"],
    );
    $i++;
  }
// Add the buttons.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );
  return  $form;
}

function camplus_pr_range_settings_form_submit($form, &$form_state) {
  $pattern = '/\d+/';
  $return = array();
  foreach ($form_state['values'] as $key => $value) {
    $subject = $key;
    if(strstr($key, 'pr_range_begin')) {
      // $range_settings[$key] = $form_state['values'][$key];
      preg_match($pattern, $subject, $matches);
      $range_settings[$matches[0]]['begin'] = $form_state['values'][$key];
    }elseif(strstr($key, 'pr_range_end')) {
      // $range_settings[$key] = $form_state['values'][$key];
      preg_match($pattern, $subject, $matches);
      $range_settings[$matches[0]]['end'] = $form_state['values'][$key];
    }elseif(preg_match($pattern, $subject, $matches)) {
      $file_settings[$key] = $form_state['values'][$key];
    }

  }
  variable_set('camplus_pr_file_settings', $file_settings);
  variable_set('camplus_pr_range_settings', $range_settings);
}

function theme_camplus_pr_range_settings_form($variables) {
  $form = $variables['form'];
  // $errors = form_get_errors() != FALSE ? form_get_errors() : array();
  $rows = array();
  foreach (element_children($form) as $i) { //dpm($key);
    if (isset($form[$i]['range'])) {
      $row = array();
      $row[] = $i+1;
      $row[] = drupal_render($form[$i]['range']["pr_range_begin_$i"]);
      $row[] = drupal_render($form[$i]['range']["pr_range_end_$i"]);
      $row[] = drupal_render($form[$i]["pr_quofile_require_$i"]);;
      $row[] = drupal_render($form[$i]["pr_quo_file_no_$i"]);;
      $row[] = drupal_render($form[$i]["pr_ref_file_require_$i"]);;
      $row = array('data' => $row);
      $rows[] = $row;
    }
  }
  if (empty($rows)) {
    $rows[] = array(array('data' => $form['#empty_text'], 'colspan' => '2'));
  }
  $rows[] = array(array('data' => drupal_render($form['name']) .drupal_render($form['add']), 'colspan' => 7));
  $header = array(t('No.'), t('Beginning price'), t('Ending price'), t('Quotation file required'), t('No. of Ref.Supplier(s)'), t('Ref. Quotation File Required'));
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'approvable_role')));
  $output .= drupal_render_children($form);


  $warning = '<div class="messages warning">'.t('Enter the Price Range(s) in respect to different Approval Hierarchy<br/>Note: The following settings are critical, please make sure you know what your are doing!').'</div>';
  return $warning.$output;
}

function camplus_pr_settings_form() {
  $form['camplus_pr_settings_range'] = array(
    '#type' => 'textfield',
    '#title' => t('No. of Price Range'),
    '#default_value' => variable_get('camplus_pr_settings_range', '5'),
    '#description' => 'How many price rangs in Approval process',
    '#required' => TRUE,
  );
  $form['camplus_pr_financial_year_begin'] = array(
    '#type' => 'textfield',
    '#title' => t('Financial Year Begin'),
    '#default_value' => variable_get('camplus_pr_financial_year_begin', '09-01'),
    '#required' => TRUE,
  );  
  $form['camplus_pr_financial_year_end'] = array(
    '#type' => 'textfield',
    '#title' => t('Financial Year End'),
    '#default_value' => variable_get('camplus_pr_financial_year_end', '08-31'),
    '#required' => TRUE,
  );    
  $form['camplus_pr_enable_mixable_key'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Budget Pool'),
    '#default_value' => variable_get('camplus_pr_enable_mixable_key', 1),
    '#description' => 'Enable Budget Pool allows "borrowing" money across other Budget Item(s) with the same Budget Pool Key',//是否允许通用,默认允许
  );  
  $form['camplus_pr_email_notification_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Email notification'),
    '#default_value' => variable_get('camplus_pr_email_notification_enable', '0'),
    '#description' => '',
  ); 
  $form['camplus_pr_email_notification_addr'] = array(
    '#type' => 'textfield',
    '#title' => t('Enable Email notification to'),
    '#default_value' => variable_get('camplus_pr_email_notification_addr', 'admin@admin.com'),
    '#description' => '',
    // '#required' => TRUE,
  );
  $form['camplus_pr_lock_function_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable "Lock" function for the Purchase Request Submission'),
    '#default_value' => variable_get('camplus_pr_lock_function_enable', '0'),
    '#description' => '',
  ); 
  $roles = user_roles(TRUE, 'camplus purchase request approvable');
  $form['camplus_pr_unlock_role'] = array(
    '#type' => 'select',
    '#title' => t('Choose which Role can unlock:'),
    '#default_value' => variable_get('camplus_pr_unlock_role', '16563288'),
    '#options' => $roles,
    '#description' => '',
    '#required' => TRUE,
  ); 
  $form['camplus_pr_help_staff_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Office Submission'),
    '#default_value' => variable_get('camplus_pr_help_staff_enable', '0'),
    '#description' => 'Enable Office Submission means Office Staff Mady help teachers to create, fill and submit the Purchase Request, but the Applicant will still be the teacher who request the purchase.',// Your can give role permissions of "Office Submission"
  );
  $form['camplus_pr_help_role'] = array(
    '#type' => 'select',
    '#title' => t('Choose which Role to execute Submission for others:'),
    '#default_value' => variable_get('camplus_pr_help_role', '166149871'),
    '#options' => user_roles(TRUE,'create purchase_request content'),
    '#description' => '',
    '#required' => TRUE,
  ); 
  $form['camplus_pr_no_pattern_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('PR Reference Number Pattern Prefix'),
    '#default_value' => variable_get('camplus_pr_no_pattern_prefix', 'PR'),
    '#description' => 'The resulet will be "prefix-[financial_year]-[nid]"',
    '#required' => TRUE,
  );   
  $form['camplus_pr_show_budget_history'] = array(
    '#type' => 'textfield',
    '#title' => t('Show Budget History'),
    '#default_value' => variable_get('camplus_pr_show_budget_history', '1'),
    '#description' => '显示最近几年的预算报表？',
    '#required' => TRUE,
  );   
  $form['warning_info'] = array('#markup' => t('Note: The following settings are critical, please make sure you know what your are doing!'),
  '#weight'=>-10,'#prefix' => '<div class="messages warning">',
  '#suffix' => '</div>');
  drupal_add_js(drupal_get_path('module', 'camplus_pr').'/camplus_pr_admin.js');
  return system_settings_form($form);
}

function camplus_pr_approve_settings_form() {

  $count_rows =  variable_get('camplus_pr_settings_range', '5');
  $roles = user_roles(TRUE, 'camplus purchase request approvable');
  $order = array();
  $camplus_pr_approvable_role_weight = variable_get('camplus_pr_approvable_role_weight','');
  $camplus_pr_approvable_role_involved = variable_get('camplus_pr_approvable_role_involved','');
  foreach ($roles as $rid => $role_name) {
    if (in_array($role_name, array('administrator'))) continue; 
    if(!$camplus_pr_approvable_role_involved[$role_name]) continue;
    if(!isset($camplus_pr_approvable_role_involved[$role_name])) continue;
    if(isset($camplus_pr_approvable_role_weight[$role_name])) {
      $weight = $camplus_pr_approvable_role_weight[$role_name];
      $order[$weight] = array('rid'=>$rid,'name'=>$role_name);
    }
  }
  ksort($order,SORT_NUMERIC);

  $workflow_settings = variable_get('camplus_pr_workflow_settings', '');
  for($i = 0; $i < $count_rows; $i++) {
    foreach ($order as $key => $role) {
      $default_value = 0;
      if(isset($workflow_settings[$i][$role['rid']])) {
        $default_value = $workflow_settings[$i][$role['rid']];
      }
      $form[$i][$i.'-workflow-'.$role['rid']] = array(
        '#type' => 'checkbox',
        '#default_value' => $default_value,
      );
    }
  }


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );
  return  $form;
}

function camplus_pr_approve_settings_form_submit($form, &$form_state) {
  // foreach ($form_state['values'] as $key => $value) {
  //   if(strstr($key, '-workflow-')) {
  //     $workflow_settings[$key] = $form_state['values'][$key];
  //   }
  // }

  foreach ($form_state['values'] as $key => $value) {
    $subject = $key;
    if(strstr($key, '-workflow-')) {
      // $range_settings[$key] = $form_state['values'][$key];
      preg_match('/\d+-/', $subject, $matches);
      $index = str_replace('-', '', $matches[0]);
      preg_match('/-\d+/', $subject, $matches);
      $rid = str_replace('-', '', $matches[0]);
      $workflow_settings[$index][$rid] = $form_state['values'][$key];
    }
  }
  variable_set('camplus_pr_workflow_settings', $workflow_settings);

}

function theme_camplus_pr_approve_settings_form($variables) {
  $form = $variables['form'];
  // $errors = form_get_errors() != FALSE ? form_get_errors() : array();
  $rows = array();
  $count_rows =  variable_get('camplus_pr_settings_range', '5');
  $roles = user_roles(TRUE, 'camplus purchase request approvable');

  $camplus_pr_approvable_role_weight = variable_get('camplus_pr_approvable_role_weight','');
  $camplus_pr_approvable_role_involved = variable_get('camplus_pr_approvable_role_involved','');
  $order = array();
  foreach ($roles as $rid => $role_name) {
    if (in_array($role_name, array('administrator'))) continue;
    if(isset($camplus_pr_approvable_role_weight[$role_name])){
      $weight = $camplus_pr_approvable_role_weight[$role_name];
      $order[$weight] = array('rid'=>$rid,'name'=>$role_name);
    }
  }
  ksort($order,SORT_NUMERIC);  

 $range_settings =  variable_get('camplus_pr_range_settings');

  for($i = 0; $i < $count_rows; $i++) {
    $row = array();
    $row[] = $range_settings[$i]["begin"] .'--'. $range_settings[$i]["end"];
    foreach ($order as $key => $role) {
      $row[] = drupal_render($form[$i][$i.'-workflow-'.$role['rid']]);
    }
    $row = array('data' => $row);
    $rows[] = $row;
  }
  $header[] = 'Price Range (HK$)';
  foreach ($order as $key => $role) {
    $header[] = $role['name'];
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => $form['#empty_text'], 'colspan' => '2'));
  }
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'approvable_role')));
  $output .= drupal_render_children($form);
  $warning = '<div class="messages warning">'.t('Click the Role(s) involved in the Approval Workflow process with respected Price Range<br>Note: The following settings are critical, please make sure you know what your are doing!
    ').'</div>';
  return $warning.$output;
}




function camplus_pr_budget_settings_form() {
  if(isset($_REQUEST['financial_year'])){
    // $financial_year = $_REQUEST['financial_year'];
    $financial_year = $_REQUEST['financial_year'].'-01-01 00:00:00';
  }else {
    $financial_year = NULL;
  }
  $groups = array();
  $public_groups = druedu_user_get_nodes_by_group('school_department');
  foreach ($public_groups as $g_nid => $g_node) {
    
    if(arg(1) == 'my_budget_report' || (arg(0) == 'pr' && arg(1) === NULL)) {
      if(!og_is_member($group_type = 'node', $g_nid, $entity_type = 'user', $entity = NULL, $states = array(OG_STATE_ACTIVE)))
        continue;
    }

    $groups[$g_nid]['gid'] = $g_nid;
    $groups[$g_nid]['depth'] = 0;
    $groups[$g_nid]['parent'] = 0;
    $groups[$g_nid]['type'] = 'school_department';
    $groups[$g_nid]['name'] = $g_node->title; 
    //($grade, $subject = null, $class = null, $grade_group_content = 'subject', $subject_group_content = 'class')
    // $all_subjects_node = druedu_user_get_nodes_by_group($g_nid, $subject = null, $class = null, $grade_group_content = 'budget_item');
    $all_subjects_node = camplus_pr_get_bis_by_year($g_nid,$financial_year);
    foreach ($all_subjects_node as $s_nid => $s_node) {
      $groups[$s_nid]['gid'] = $s_nid;
      $groups[$s_nid]['depth'] = 1;
      $groups[$s_nid]['parent'] = $g_nid;
      $groups[$s_nid]['type'] = 'budget_item';
      $groups[$s_nid]['name'] = $s_node->title;
    }
  }

  $form['#tree'] = TRUE;
  $form['groups'] = array(
    '#tree' => TRUE,
  );
  $years_count = variable_get('camplus_pr_show_budget_history', '1');//this year & next year
  $history_link = '';
  $base_path = url(NULL, array('absolute' => TRUE)) . ('?q=');
  $base_path .= 'pr/'.arg(1);
  while ($years_count) {
    $history_link .= l((date('Y')-$years_count-1).' - '.(date('Y')-$years_count),'pr/'.arg(1),array ('query' => array ('financial_year' =>date('Y')-$years_count)) ).'&nbsp;&nbsp;';
    $options[$base_path.'&financial_year='.(date('Y')-$years_count)] = (date('Y')-$years_count-1).' - '.(date('Y')-$years_count);
    $years_count--;
  }
  $options[$base_path.'&financial_year='.date('Y')] = (date('Y')-$years_count-1).' - '.(date('Y')-$years_count);
  $options[$base_path.'&financial_year='.(date('Y')+1)] = (date('Y')-$years_count).' - '.(date('Y')-$years_count+1);
  // $form['financial_year'] = array(
  //   '#markup' => $history_link.'&nbsp;&nbsp;'.l((date('Y')-1).' - '.date('Y'),'pr/'.arg(1)).'&nbsp;&nbsp;'.l(date('Y').' - '.(date('Y')+1),'pr/'.arg(1),array ('query' => array ('financial_year' =>date('Y')+1)) ),
  // );

      // Prepare the data
  $destination = variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files');
  global $user;
  if (file_exists($destination."/budget-report-$user->uid.xls")) {//&& arg(1)!='my_budget_report'
    $form['budget_report'] = array(
      '#markup' => '<a href="/sites/default/files/budget-report-'.$user->uid.'.xls">Download as Excel file</a>',
    );
  }

  $form['select_year'] = array(
   '#type' => 'select',
   '#title' => t('Selected'),
   '#options' => $options,   
   '#default_value' => $base_path.'&financial_year='.(date('Y')+1),
  );
  if(isset($_REQUEST['financial_year'])) {
    $form['select_year']['#default_value'] = $base_path.'&financial_year='.$_REQUEST['financial_year'];
  }
  // if(!isset($_REQUEST['financial_year'])) {
  //   $form['select_year']['#default_value'] = $base_path.'&financial_year='.date('Y');
  // }
  // l($text = 10, $path = 'search/all', $options = array ('path' => '/search/all', 'query' => array ('s' => 'teacher', 'items_per_page' => 10)));
  $order = 1;
  if(isset($groups['-1']))unset($groups['-1']);
  foreach ($groups as $gid => $group) {
      $form['groups'][$gid]['gid'] = array(
        '#type' => 'hidden',
        '#value' => $groups[$gid]['gid'],
      );
      $form['groups'][$gid]['parent'] = array(
        '#type' => 'hidden',
        // Yes, default_value on a hidden. It needs to be changeable by the javascript.
        '#default_value' => $groups[$gid]['parent'],
      );
      $form['groups'][$gid]['depth'] = array(
        '#type' => 'hidden',
        // Same as above, the depth is modified by javascript, so it's a default_value.
        '#default_value' =>  $groups[$gid]['depth'],
      );
      $form['groups'][$gid]['title'] = array(
        '#type' => 'hidden',
        // Same as above, the depth is modified by javascript, so it's a default_value.
        '#default_value' =>   $groups[$gid]['name'],
      );

    $form['groups'][$gid]['#group'] = $groups[$gid];
    $form['groups'][$gid]['#weight'] = $order;
    $form['groups'][$gid]['weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Weight for @title', array('@title' => $group['name'])),
      '#title_display' => 'invisible',
      '#size' => 4,
      '#default_value' => $order,
      '#attributes' => array('class' => array('role-weight')),
    );
    $order++;

  }
  drupal_add_js('jQuery(document).ready(function () { jQuery(function(){
      // bind change event to select
      jQuery("#camplus-pr-budget-settings-form #edit-select-year").bind("change", function () {
          var url = jQuery(this).val(); // get selected value
          if (url) { // require a URL
              window.location = url; // redirect
          }
          return false;
      });
    });});', 'inline');
  return $form;
}

function theme_camplus_pr_budget_settings_form($variables) {
  global $debug;
  $form = $variables['form'];
  $header = array(
    t('Budget item'),
    t('Weight'),
    t('Description'),
    t('Budget Amount'),
    t('Approved Expenses'),//已批支出
    t('Pending Expenses'),//待批支出
    t('Budget Balance'),//预算余额
    t('Allowance'),
    t('Maximum Balance'),//max余额
    t('Used(%)'),
    // t('Budget Pool Key'),
    // t('Budget Pool Balance'),
    // t('Operations')
    // array('data' => , 'colspan' => 2)
    );
  if(arg(1)!='my_budget_report') {
     array_push($header,t('Budget Pool Key'));
     array_push($header,t('Budget Pool Balance'));
  }
  $headers = array(
    t('Budget item'),
    // t('Weight'),
    t('Description'),
    t('Budget Amount'),
    t('Approved Expenses'),//已批支出
    t('Pending Expenses'),//待批支出
    t('Budget Balance'),//预算余额
    t('Allowance'),
    t('Maximum Balance'),//max余额
    t('Used(%)'),
    t('Budget Pool Key'),
    t('Budget Pool Balance'),
    // t('Operations')
    // array('data' => , 'colspan' => 2)
    );
  global $user;
  if(user_access('camplus budget settings') || in_array('administrator',$user->roles)) {
    // unset($header[ t('Operations')]);
    array_push($header,t('Operations'));
  }
  $rows = array();
  $datas = array();
  $budget_amount = 0;
  $total_approved = 0;
  $total_pending = 0;
  $total_left = 0;
  $total_allowance = 0;
  $total_max_balance = 0;
  $bis = element_children($form['groups']);
  $next_node_type = 'school_department';
  foreach ($bis as $key=>$gid) {
   
    $group = &$form['groups'][$gid];
    $name = $group['#group']['name'];
    $row = array();
    $data = array();
    $node = node_load($gid);
    {//in_array($gid, array(DRUPAL_ANONYMOUS_RID, DRUPAL_AUTHENTICATED_RID))
     

      $row[] = (isset($group['#group']['depth']) && $group['#group']['depth'] > 0 ? theme('indentation', array('size' => $group['#group']['depth'])) : ''). t('@name', array('@name' => $name));
      $data[] = t('@name', array('@name' => $name));
      $group['gid']['#attributes']['class'] = array('group-id');
      $group['parent']['#attributes']['class'] = array('group-parent');
      $group['depth']['#attributes']['class'] = array('group-depth');

      $row[0] .= drupal_render($group['parent']) . drupal_render($group['gid']) . drupal_render($group['depth']);
      //$group['weight']['#attributes']['class'] = array('term-weight');
      $form['groups'][$gid]['weight']['#attributes']['class'] = array('group-weight');
      $row[] = drupal_render($form['groups'][$gid]['weight']);
      // $data[] = '';

      $total_data = array();
      if($node->type == 'budget_item') {
        if(isset($node->field_pr_budget[LANGUAGE_NONE])) {
          $field_pr_budget = (int) $node->field_pr_budget[LANGUAGE_NONE][0]['value'];
          $description = '';
          if(isset($node->body[LANGUAGE_NONE][0]['safe_value'])) $description = $node->body[LANGUAGE_NONE][0]['safe_value'];
          $row[] =  $description;
          $row[] = sprintf("%01.2f", $field_pr_budget);

          $budget_amount += $field_pr_budget;
          $data[] =  $description;
          $data[] = $field_pr_budget;
        }else{ 
          $field_pr_budget = 0.00;
          $row[] = '-';
          $row[] = '-';
          $budget_amount = 0;
          $total_approved = 0;
          $total_pending = 0;
          $total_left = 0;
          $total_allowance = 0;
          $total_max_balance = 0;
          $data[] = '-';
          $data[] = '-';
        }

       //已批支出 get all PRs
        $budget_nid = $gid;
        $prs = camplus_pr_get_prs($budget_nid);
        // $prs = druedu_user_get_nodes_by_group($gid, $subject = null, $class = null, $grade_group_content = 'purchase_request');

         $pending = 0;
         $approved = 0;
         $rejectd = 0;
         // get  approved appending and rejectd

         $widgets = rate_get_active_widgets('node', 'purchase_request');//$pr_node->type
         foreach ($prs as $nid => $pr_node) {
            // 排除canceled PRs
            $flags = flag_get_counts('node', $nid, $reset = FALSE);
            if(isset($flags['cancel']) && $flags['cancel']){
              if($debug) dpm('canceled pr:'.$nid,__LINE__);
               continue;
            }
           //get pr item
           foreach ($pr_node->field_budget_items[LANGUAGE_NONE] as $key => $value) {
            if($value['target_id'] ==  $budget_nid) {
              //field_budget_items_amount_index
              $bi_index = $key;
              break;
            }
           }
            foreach ($widgets as $widget_id => $widget) {
              if($widget->name == 'approve'){
                $widget->id = $widget_id;
                $approve_status = _rate_pr_check_permissions($pr_node,$widget);
                switch ($approve_status['workflow_status']) {
                  case 'pending':
                    $pending += $pr_node->field_budget_items_amount[LANGUAGE_NONE][$bi_index]['value'];
                    break;
                  case 'approved':
                    $approved += $pr_node->field_budget_items_amount[LANGUAGE_NONE][$bi_index]['value'];
                    break;
                  default: //rejectd FALSE
                    $rejectd += $pr_node->field_budget_items_amount[LANGUAGE_NONE][$bi_index]['value'];
                    break;
                }
                break;
              }else{
                continue;
              }
            }
         }
        $row[] = sprintf("%01.2f", $approved);

        $total_approved += $approved;
        $data[] = sprintf("%01.2f", $approved);
        $row[] = sprintf("%01.2f", $pending);
        $total_pending += $pending;
        $data[] = sprintf("%01.2f", $pending);
        $row_d = $field_pr_budget - $approved - $pending;
        $row[] = sprintf("%01.2f", $field_pr_budget - $approved - $pending);// '预算余额';
        $total_left += $row_d;
        $data[] = sprintf("%01.2f", $field_pr_budget - $approved - $pending);// '预算余额';
        if(isset($node->field_pr_allowance[LANGUAGE_NONE])) {
          $row_e = $node->field_pr_allowance[LANGUAGE_NONE][0]['value'];
          $row[] = $row_e;
          $data[] = $row_e;
        }else{
          $row_e = 0;
          $row[] = '-';
          $data[] = '-';
        }
        $total_allowance += $row_e;
        $row[] = sprintf("%01.2f", $row_d + $row_e);//max余额
        $total_max_balance += $row_d + $row_e;
        $data[] = sprintf("%01.2f", $row_d + $row_e);//max余额
        if(isset($node->field_pr_budget[LANGUAGE_NONE][0]['value'])) {
          $row[] = sprintf("%01.2f%%", ($approved + $pending)/$node->field_pr_budget[LANGUAGE_NONE][0]['value']*100);//%
          $data[] = sprintf("%01.2f%%", ($approved + $pending)/$node->field_pr_budget[LANGUAGE_NONE][0]['value']*100);
        }else {
          $row[] = '0.00%';
          $data[] = '0.00%';
        }
        if(arg(1)!='my_budget_report') {
          $mixable_amount = get_bi_mixable_amount($gid);
          if(isset($node->field_mixable_key[LANGUAGE_NONE])) {
            $row[] = $node->field_mixable_key[LANGUAGE_NONE][0]['value'];
            $data[] = $node->field_mixable_key[LANGUAGE_NONE][0]['value'];
            $row[] = $mixable_amount.'*';//'通用余额';
            $data[] = $mixable_amount;//'通用余额';
          }else{
            $row[] = '-';
            $data[] = '-';
            $row[] = $mixable_amount;//'通用余额';
            $data[] = $mixable_amount;//'通用余额';
          }
        }

        
        if(user_access('camplus budget settings') || in_array('administrator',$user->roles)) {
          $row[] = l(t('setting'), 'node/' . $gid.'/edit');
        }
        $rows[$gid] = array('data' => $row, 'class' => array('draggable','locked'));


      if(isset($bis[$key+1])) {
        $next_node = node_load($bis[$key+1]);
        $next_node_type = $next_node->type;
      }
      //
      if($next_node_type == 'school_department'|| !isset($bis[$key+1])) {
        $total=array();
        $total[] = t('Total');$total_data[] = t('Total');//Amount
        $total[] ='1'; $total_data[] = t('description');//des
        $total[] =''; 

        $total[] = sprintf("%01.2f", $budget_amount);
        $total_data[] = sprintf("%01.2f", $budget_amount);
        $total[] = sprintf("%01.2f", $total_approved); 
        $total_data[] = sprintf("%01.2f", $total_approved);
        $total_approved = 0;//已批支出

        $total[] = sprintf("%01.2f", $total_pending); 
        $total_data[] = sprintf("%01.2f", $total_pending);$total_pending = 0;//待批支出
        $total[] = sprintf("%01.2f", $total_left); 
        $total_data[] = sprintf("%01.2f", $total_left);
        $total[] = sprintf("%01.2f", $total_allowance);
        $total_data[] = sprintf("%01.2f", $total_allowance); $total_allowance = 0;//Allowance
        $total[] = sprintf("%01.2f", $total_max_balance); 
        $total_data[] = sprintf("%01.2f", $total_max_balance);$total_max_balance = 0; //max余额
        $total[] = sprintf("%01.2f%%", 100*($budget_amount-$total_left)/$budget_amount);//%
        $total_data[] = sprintf("%01.2f%%", 100*($budget_amount-$total_left)/$budget_amount);
        $budget_amount = 0;//Amount
        $total_left = 0;//预算余额

        if(arg(1)!='my_budget_report') {
          $total[] ='';//Mixable Key
          $total[] ='';//通用余额
          $total_data[] = '';//des
          $total_data[] = '';//des
        }
        $total[] = '';//des
        $rows["total_$key"] = array('data' => $total, 'class' => array('draggable','locked'));
        // array_merge($datas, $total_data);
       
      }

      }else {
        $row[] ='';$data[] = '';//Amount
        $row[] ='';$data[] = '';//des
        $row[] ='';$data[] = '';//已批支出
        $row[] ='';$data[] = '';//待批支出
        $row[] ='';$data[] = '';//预算余额
        $row[] ='';$data[] = '';//Allowance
        $row[] ='';$data[] = '';//max余额
        $row[] ='';$data[] = '';//%
        if(arg(1)!='my_budget_report') {
          $row[] ='';$data[] = '';//Mixable Key
          $row[] ='';$data[] = '';//通用余额
        }
        if(user_access('camplus budget settings') || in_array('administrator',$user->roles)) {
          $row[] ='';//l(t('edit'), 'node/' . $gid.'/edit');
        }
        $rows[$gid] = array('data' => $row, 'class' => array('draggable','locked'));




      }
      $datas[] = $data;
      if($next_node_type == 'school_department'|| !isset($bis[$key+1])) {
         $datas[] = $total_data;
      }

    }
  }
  // Add drag and drop if parent fields are present in the form.
    drupal_add_tabledrag('groups_tree', 'match', 'parent', 'group-parent', 'group-parent', 'group-id', FALSE);
    drupal_add_tabledrag('groups_tree', 'depth', 'group', 'group-depth', NULL, NULL, FALSE);
    drupal_add_tabledrag('groups_tree', 'order', 'sibling', 'group-weight');
    drupal_add_js(drupal_get_path('module', 'druedu_user_tree') . '/druedu_user_tree.js');
  
 

  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'groups_tree')));
  $output = drupal_render_children($form).$output;


    // Prepare the data
  $destination = variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files');
  
  // $headers = array('ID', 'Name', 'Type', 'parents', 'Department');

  // $data = array();
  // foreach ($rows as $key => $value) {
  //   $data[] = $value['data'];
  // }
  $file_name = "budget-report-$user->uid.xls";
  if (file_exists($destination. '/' .$file_name)) {
    drupal_unlink($destination. '/' .$file_name);
  }
  $path = file_create_filename($file_name, $destination);

  require_once drupal_get_path('module', 'phpexcel').'/phpexcel.inc';
  if(druedu_phpexcel_export($headers, $datas, $path)){ //@see phpexcel_export
    // drupal_set_message(t('Click '.l('here',$path)).' to download.', 'status');
  }

  return $output;
}