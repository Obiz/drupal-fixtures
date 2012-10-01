<?php

/**
 * Create all users
 */
function fixtures_create_users() {
  $fixtures = fixtures_get_fixtures('user');
  foreach ($fixtures as $fixture) {
    foreach ($fixture as $user_name => $user_array) {
      $user = fixture_create_user($user_array);
    }
  }
  return "debugging fixtures";
}

/**`
 * Create single user from YAML array
 */
function fixture_create_user($user_array) {
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $user = new stdClass();
  $user->name = $user_array['name'];
  $user->pass = user_hash_password($user_array['pass']);
  $user->pass_raw = $user->pass;
  $user->mail = $user_array['mail'];
  $user->status = 1;
  $roles = array(DRUPAL_AUTHENTICATED_RID => TRUE);
  foreach (preg_split('/\s*,\s*/', $user_array['roles'], 0, PREG_SPLIT_NO_EMPTY) as $role_name) {
    $role = user_role_load_by_name($role_name);
    if ($role != null) {
      $roles[$role->rid] = TRUE;
    }
    else {
      throw new Exception("User role not found: '$role_name'", 1);
    }
  }
  $user->roles = $roles;
  $user->timezone = variable_get('date_default_timezone', '');
  user_save($user);
  return $user;
}
