<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class Row extends dcomponent {
    function propTypes() {
      return array(
        'children' => propType::Collection(),
        'id' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $id = isset($props['id']) ? 'id="' . $props['id'] . '"' : '';
      $block = array(
        '#type' => 'markup',
        '#prefix' => '<div class="row"' . $id . '>',
        '#suffix' => '</div>',
      );
      
      foreach($props['children'] as $child) {
          $block[] = $child;
      }
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/row/dls_components.row.css';
          
      return $block;
    }
  }