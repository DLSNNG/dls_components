<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class StretcherContainer extends dcomponent {
    function propTypes() {
      return array(
        'children' => propType::Collection(),
      );
    }
    
    function render() {
      $props = $this->props;
      $block = array(
        '#type' => 'markup',
        '#prefix' => '<div class="stretcher-container"><div class="stretcher-div">',
        '#suffix' => '</div></div>',
      );
      
      foreach($props['children'] as $child) {
          $block[] = $child;
      }
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/stretcher_container/dls_components.stretcher_container.css';
          
      return $block;
    }
  }