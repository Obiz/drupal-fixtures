<?php
function fixtures_drush_command() {
  $items = array();

  $items['fixtures-all'] = array(
    'description' => 'Run the menu fixtures',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'callback' => 'fixtures_drush_create_all',
  );

  return $items;
}

function fixtures_drush_create_all() {
  // Include the menu part of the module.
  module_load_include('inc', 'fixtures', 'fixtures.menu');
  fixtures_create_menus();
  drush_log('Generating menus from YAML files in "sites/all/fixtures"', 'success');
}
