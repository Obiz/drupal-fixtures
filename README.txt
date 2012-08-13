README
======
Fixtures is an idea derived from other frameworks - in this case Symfony and Ruby on Rails.  Fixtures are a YAML way of
writing default content for your website.  If you create your Drupal based website with Fixtures, you might need a set
of default testing data to populate your site once you've installed it.

Features enables you to create your website from a "clean-build path", instead of the classic "upgrade path" approach.
This way, continuous integration is possible.  This creates a little problem: every time you do a clean install of your
drupal website, you have to create content again and again.  Fixtures is a way to permanently create content in a text
file, and the user doesn't have to know a lot about drupal.

MENU FIXTURES
=============
Define a menu tree in a file in the folder sites/all/fixtures and use the naming convention below:

menu--[machine-name].yaml
menu--main-menu.yaml
menu--other-menu.yaml

Important: note that if you specify menu items, you'll have to run them after nodes/taxonomies have been created.  Menu
items created with a path that doesn't exist yet are not saved.

NODE FIXTURES
=============
Below is a description of the node fixtures.

node--[type].yaml
node--[type]--[custom-name].yaml
--
node--article.yaml              # Any articles
node--article--batch1.yaml      # "Batch" 1 of articles
node--article--batch2.yaml      #
node--page.yaml                 # All pages, not part of any category
node--page--about.yaml          # For example all pages that are under the "About" menu item
node--page--contact.yaml        #
