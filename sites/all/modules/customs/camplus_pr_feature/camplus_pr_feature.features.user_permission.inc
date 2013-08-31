<?php
/**
 * @file
 * camplus_pr_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function camplus_pr_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'camplus budget cross sectoral'.
  $permissions['camplus budget cross sectoral'] = array(
    'name' => 'camplus budget cross sectoral',
    'roles' => array(
      'staff' => 'staff',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'camplus budget settings'.
  $permissions['camplus budget settings'] = array(
    'name' => 'camplus budget settings',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'camplus purchase request approvable'.
  $permissions['camplus purchase request approvable'] = array(
    'name' => 'camplus purchase request approvable',
    'roles' => array(
      'financial_manager' => 'financial_manager',
      'panel_head' => 'panel_head',
      'principal' => 'principal',
      'school_board' => 'school_board',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'create budget_item content'.
  $permissions['create budget_item content'] = array(
    'name' => 'create budget_item content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create purchase_request content'.
  $permissions['create purchase_request content'] = array(
    'name' => 'create purchase_request content',
    'roles' => array(
      'staff' => 'staff',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create school_department content'.
  $permissions['create school_department content'] = array(
    'name' => 'create school_department content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any budget_item content'.
  $permissions['delete any budget_item content'] = array(
    'name' => 'delete any budget_item content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any school_department content'.
  $permissions['delete any school_department content'] = array(
    'name' => 'delete any school_department content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own budget_item content'.
  $permissions['delete own budget_item content'] = array(
    'name' => 'delete own budget_item content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own purchase_request content'.
  $permissions['delete own purchase_request content'] = array(
    'name' => 'delete own purchase_request content',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own school_department content'.
  $permissions['delete own school_department content'] = array(
    'name' => 'delete own school_department content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any budget_item content'.
  $permissions['edit any budget_item content'] = array(
    'name' => 'edit any budget_item content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
      'principal' => 'principal',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any purchase_request content'.
  $permissions['edit any purchase_request content'] = array(
    'name' => 'edit any purchase_request content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
      'staff' => 'staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any school_department content'.
  $permissions['edit any school_department content'] = array(
    'name' => 'edit any school_department content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own budget_item content'.
  $permissions['edit own budget_item content'] = array(
    'name' => 'edit own budget_item content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own purchase_request content'.
  $permissions['edit own purchase_request content'] = array(
    'name' => 'edit own purchase_request content',
    'roles' => array(
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own school_department content'.
  $permissions['edit own school_department content'] = array(
    'name' => 'edit own school_department content',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag cancel'.
  $permissions['flag cancel'] = array(
    'name' => 'flag cancel',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag paid'.
  $permissions['flag paid'] = array(
    'name' => 'flag paid',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag pr_lock'.
  $permissions['flag pr_lock'] = array(
    'name' => 'flag pr_lock',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag cancel'.
  $permissions['unflag cancel'] = array(
    'name' => 'unflag cancel',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag pr_lock'.
  $permissions['unflag pr_lock'] = array(
    'name' => 'unflag pr_lock',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view all purchase request'.
  $permissions['view all purchase request'] = array(
    'name' => 'view all purchase request',
    'roles' => array(
      'financial_manager' => 'financial_manager',
      'principal' => 'principal',
      'staff' => 'staff',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'view budget report'.
  $permissions['view budget report'] = array(
    'name' => 'view budget report',
    'roles' => array(
      'financial_manager' => 'financial_manager',
      'principal' => 'principal',
      'school_board' => 'school_board',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'view loked purchase request'.
  $permissions['view loked purchase request'] = array(
    'name' => 'view loked purchase request',
    'roles' => array(
      'financial_manager' => 'financial_manager',
    ),
    'module' => 'camplus_pr',
  );

  // Exported permission: 'view my budget report'.
  $permissions['view my budget report'] = array(
    'name' => 'view my budget report',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'camplus_pr',
  );

  return $permissions;
}
