<?php
//del also before ,we need after rate,use js to ajax.
/**
 * @file Includes any rules integration provided by the module.
 */
 /**
 * implementation of hook_rules_condition_info()
 */
function rate_pr_rules_condition_info() {
  return array(
    'rate_pr_condition_all_approved' => array(
      'label' => t('If all approved the pr.'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The node.')),
      ),
      'module' => 'rate_pr',
      'group' => t('Customs'),
    ),
  'rate_pr_condition_lock' => array(
      'label' => t('If need lock'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The node.')),
      ),
      'module' => 'rate_pr',
      'group' => t('Customs'),
    ),  
  'rate_pr_condition_email' => array(
      'label' => t('If need email'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The node.')),
      ),
      'module' => 'rate_pr',
      'group' => t('Customs'),
    ),
  );
}
/**
 * Condition rate_pr_condition_all_approved
 */
function rate_pr_condition_all_approved($node) {
  $widget = _camplus_pr_get_approve_rate($node);
  if(!isset($widget->id)) return FALSE;
  $approve_status = _rate_pr_check_permissions($node,$widget);
  global $debug;
  if($debug) watchdog('ooooo1', ''.print_r($approve_status,TRUE), $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL);
  //oh no ,didn't work. should do this after done.
  //http://drupal.org/project/voting_rules
  if($approve_status['workflow_status'] == 'approved') {  
    return TRUE;
  }
  return FALSE;
}

/**
 * Condition rate_pr_condition_all_approved
 */
function rate_pr_condition_lock($node) {
  //global setting of lock
  if(!variable_get('camplus_pr_lock_function_enable', '0')) {
    return FALSE;
  }
  //指定角色 unlock时 fix
  global $user;
  if(in_array(variable_get('camplus_pr_unlock_role', '16563288'), array_keys($user->roles))) {
    watchdog(' 时 fix', array(), WATCHDOG_NOTICE, 'link');
    return FALSE;
  }
  $bis_info_all = get_bis_info_all($node->field_budget_items[LANGUAGE_NONE][0]['target_id']);
  if($bis_info_all['f'] < 0) {
    watchdog('locked pr1', 'message', array(), WATCHDOG_NOTICE, 'link');
    return TRUE;
  }

  return FALSE;
}
function rate_pr_condition_email($node) {
  //global setting of lock
  // if(!variable_get('camplus_pr_lock_function_enable', '0')) {
  //   return FALSE;
  // }
  if(!variable_get('camplus_pr_email_notification_enable', '0')) {
    return FALSE;
  }
  $bis_info_all = get_bis_info_all($node->field_budget_items[LANGUAGE_NONE][0]['target_id']);
  if($bis_info_all['f'] < 0) {
    watchdog('send eamil condition_email enough', 'message', array(), WATCHDOG_NOTICE, 'link');
    return TRUE;
  }
  return FALSE;
}
 /**
 * implementation of hook_rules_condition_info()
 */
function rate_pr_rules_action_info() {
  return array(
    'rate_pr_action_email' => array(
      'label' => t('1.Email to specific addr when mixable/locked.'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The new answer someone gives.')),
      ),
      'module' => 'rate_pr',
      'group' => t('Customs'),
    ),
    'rete_pr_og_rules_add_entitys_to_group' => array(
      'label' => t('2.Subscribe user to all children groups'),
      // 'arguments' => array(
      //   'parent_group' => array('type' => 'node', 'label' => t('The new parent group.')),
      // ),
      'parameter' => array(
        'entity' => array(
          // Do not use type 'entity' but restrict the type to group content type.
          'type' => array_keys(og_get_all_group_content_entity()),
          'label' => t('Entity'),
          'description' => t('The group content which is to be added to a group.'),
          'wrapped' => TRUE,
        ),
        'group' => array(
          'type' => array_keys(og_get_all_group_entity()),
          'label' => t('Group'),
          'wrapped' => TRUE,
        ),
      ),
      // 'base' => 'og_rules_add_entity_to_children_groups',
      'module' => 'rate_pr',
      'group' => t('Customs'),
    ),
    // 'rate_pr_action_email_to_next_role' => array(
    //   'label' => t('3.Email to next role after one approved.'),
    //   'arguments' => array(
    //     'node' => array('type' => 'node', 'label' => t('The node action on.')),
    //   ),
    //   'module' => 'rate_pr',
    //   'group' => t('Customs'),
    // ),
  );
}

/**
 * Action: Add entity to group.
 * @see og_rules_add_entity_to_children_groups
 */
function rete_pr_og_rules_add_entitys_to_group(EntityDrupalWrapper $entity, EntityDrupalWrapper $group) {
  // TODO: Add field-name.
  
  $values = array(
    'entity_type' => $entity->type(),
    'entity' => $entity->value(),
  );
  $department_node = $group->value();
  $all_bis = druedu_user_get_nodes_by_group($department_node->nid, $subject = null, $class = null, $grade_group_content = 'budget_item', $subject_group_content = 'class');
  foreach ($all_bis as $bi_nid => $bi_node) {
    og_group($group->type(), $bi_nid, $values);
    drupal_set_message('joined in '. $bi_node->title,'status', FALSE);
  }
  // og_group($group->type(), $group->getIdentifier(), $values);
}
/**
 * Condition packages_condition_packagetype
 * 1.Email to specific addr when mixable/locked.
 */
  // 1|Draft
  // 2|Locked
  // 3|Pending
  // 4|Approved
  // 5|Rejected
  // 6|Completed
  // 7|Cancelled
function rate_pr_action_email($node) {
   //Provide the the old answer as parameter to unflag?
   //do something, no return.
  // drupal_mail($module, $key, $to, $language, $params = array(), $from = NULL, $send = TRUE);
 if($node->field_pr_status[LANGUAGE_NONE][0]['value'] == '2') {
    watchdog('value==2', 'message', array(), WATCHDOG_NOTICE, 'link');
 }
 //begin
  
  $module = 'rate_pr';
  $key = 'lock_email';

  // Specify 'to' and 'from' addresses.
  // Specify 'to' and 'from' addresses.
  $to =  variable_get('camplus_pr_email_notification_addr', 'admin@admin.com');
  $from = variable_get('site_mail', 'admin@example.com');

  // "params" loads in additional context for email content completion in
  // hook_mail(). In this case, we want to pass in the values the user entered
  // into the form, which include the message body in $form_values['message'].
  $params = array(
    'subject' => $node->title,
    'message' => "The purchase request of $node->title is locked. Please go to ".url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q=pr/locked')." to review it.",
    'body' => "The purchase request of $node->title is locked. Please go to ".url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q=pr/locked')." to review it.",
  );
  // The language of the e-mail. This will one of three values:
  // * user_preferred_language(): Used for sending mail to a particular website
  //   user, so that the mail appears in their preferred language.
  // * global $language: Used when sending a mail back to the user currently
  //   viewing the site. This will send it in the language they're currently
  //   using.
  // * language_default(): Used when sending mail to a pre-existing, 'neutral'
  //   address, such as the system e-mail address, or when you're unsure of the
  //   language preferences of the intended recipient.
  //
  // Since in our case, we are sending a message to a random e-mail address that
  // is not necessarily tied to a user account, we will use the site's default
  // language.
  $language = language_default();

  // Whether or not to automatically send the mail when drupal_mail() is
  // called. This defaults to TRUE, and is normally what you want unless you
  // need to do additional processing before drupal_mail_send() is called.
  $send = TRUE;
  // Send the mail, and check for success. Note that this does not guarantee
  // message delivery; only that there were no PHP-related issues encountered
  // while sending.
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your lock eamil has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }

}

/**
 * rate_pr_action_email_to_next_role
 */
// function rate_pr_action_email_to_next_role($node) {
//  //begin
  
//   $module = 'rate_pr';
//   $key = 'email_to_next_role';

//   // Specify 'to' and 'from' addresses.
//   // $to =  variable_get('camplus_pr_email_notification_addr', 'admin@admin.com');
//    // Avoid sending emails to members of two or more target role groups.
//   $role_involved = unserialize($node->field_pr_role_involved[LANGUAGE_NONE][0]['value']);
//   $workflow_settings_node = array_filter($role_involved);
//   $workflow_settings_node = array_keys($workflow_settings_node);

//   watchdog('workflow_settings_node', 'workflow_settings_node <pre>'.print_r($workflow_settings_node,TRUE), array(), WATCHDOG_NOTICE, 'link');
//   // _rate_pr_check_permissions begin
//     if($node->type == 'purchase_request') {

//       if(isset($node->field_pr_status[LANGUAGE_NONE][0]['value']) && $node->field_pr_status[LANGUAGE_NONE][0]['value'] == 3) {
//         //check if all approved. if so ,change status to 4.
//         $widget = _camplus_pr_get_approve_rate($node);
//         if(!isset($widget->id)) return;
//         $approve_status = _rate_pr_check_permissions($node,$widget);
//       }
//     }
//   // _rate_pr_check_permissions end

//   $next_rid = $workflow_settings_node[$approve_status['approved_counts']+1]?$workflow_settings_node[$approve_status['approved_counts']+1]:0;
//   // $rids = implode(',', $role_involved);
//   $result = db_query('SELECT DISTINCT u.mail FROM {users} u INNER JOIN {users_roles} r ON u.uid = r.uid WHERE r.rid = '.$next_rid);
//   watchdog('next_rid', $next_rid, array(), WATCHDOG_NOTICE, 'link');

//   $from = variable_get('site_mail', 'admin@example.com');

//   // "params" loads in additional context for email content completion in
//   // hook_mail(). In this case, we want to pass in the values the user entered
//   // into the form, which include the message body in $form_values['message'].
//   $params = array(
//     'subject' => $node->title,
//     'message' => "<p>rate_pr_action_email_to_next_role</p>",
//     'body' => "<p>Hello 22222</p>",
//   );
//   // The language of the e-mail. This will one of three values:
//   // * user_preferred_language(): Used for sending mail to a particular website
//   //   user, so that the mail appears in their preferred language.
//   // * global $language: Used when sending a mail back to the user currently
//   //   viewing the site. This will send it in the language they're currently
//   //   using.
//   // * language_default(): Used when sending mail to a pre-existing, 'neutral'
//   //   address, such as the system e-mail address, or when you're unsure of the
//   //   language preferences of the intended recipient.
//   //
//   // Since in our case, we are sending a message to a random e-mail address that
//   // is not necessarily tied to a user account, we will use the site's default
//   // language.
//   $language = language_default();

//   // Whether or not to automatically send the mail when drupal_mail() is
//   // called. This defaults to TRUE, and is normally what you want unless you
//   // need to do additional processing before drupal_mail_send() is called.
//   $send = TRUE;
//   // Send the mail, and check for success. Note that this does not guarantee
//   // message delivery; only that there were no PHP-related issues encountered
//   // while sending.
//   $module = 'rate_pr';
//   $message = array('result' => TRUE);
//   foreach ($result as $row) {
//     watchdog('$row->mail', $row->mail, array(), WATCHDOG_NOTICE, 'link');
//     $message = drupal_mail($module, $key, $row->mail, language_default(), $params, $from);
//     if (!$message['result']) {
//       break;
//     }
//   }

//   if ($message['result'] == TRUE) {
//     watchdog('status',t('Your rate_pr_action_email_to_next_role eamil has been sent.'), array(), WATCHDOG_NOTICE, 'link');
//     drupal_set_message(t('Your eamil has been sent.'));
//   }
//   else {
//     watchdog('status',t('There was a problem sending your message and it was not sent.'), array(), WATCHDOG_NOTICE, 'link');
//     drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
//   }

// }