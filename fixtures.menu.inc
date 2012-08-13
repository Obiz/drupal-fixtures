<?php

function fixtures_create_menus() {
  // Getting an array of fixtures, all files in the fixtures folder, that have 'menu--' as a beginning string
  $fixtures = fixtures_get_fixtures('menu');
  foreach ($fixtures as $fixture) {
    foreach ($fixture as $menu_name => $menu_array) {
      // entering loop for each defined menu in this file.
      // check if menu with key doesn't already exist, otherwise create new menu
      $menu = menu_load($menu_name);
      if (!$menu) {
        $menu = array();
        $menu['menu_name'] = $menu_name;
        $menu['title'] = $menu_array['title'];
        $menu['description'] = $menu_array['description'];
        menu_save($menu);
        drupal_set_message(t("Created menu #name.", array('#name' => $menu_name)));
      }
      else {
        drupal_set_message(t("Menu #name already exists.", array('#name' => $menu_name)));
      }

      // Create menu items
      _fixtures_create_menu_item($menu_array['items'], $menu, 0);
    }
  }
  return "debugging fixtures";
}

function _fixtures_create_menu_item($items, $menu, $plid = 0) {
  foreach ($items as $item_key => $item_value) {
    $item = array();
    $item['link_path'] = $item_value['link'];
    $item['link_title'] = $item_value['title'];
    $item['menu_name'] = $menu['menu_name'];
    $item['plid'] = $plid;
    menu_link_save($item);
    if (array_key_exists('items', $item_value) && is_array($item_value['items'])) {
      _fixtures_create_menu_item($item_value['items'], $menu, $item['mlid']);
    }
  }
}
