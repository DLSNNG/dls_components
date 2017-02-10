<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class OrbitalItem extends dcomponent {
    function propTypes() {
      return array(
        'contents' => propType::Collection(),
        'size' => propType::String(),
        'rotate' => propType::String(),
      );
    }
    
    function render() {
      $props = $this->props;
      $item = array(
        '#type' => 'markup',
        'contents' => $props['contents'],
        '#prefix' => '<div class="orbital-item"' .
                          'style="transform: rotate(-' . $props['rotate'] . ');">',
        '#suffix' => '</div>'
      );
      $block = array(
        '#type' => 'markup',
        'item' => $item,
        '#prefix' => '<div class="orbital-wrapper"' .
                          'style="transform: rotate(' . $props['rotate'] . ');' .
                                ' width: ' . $props['size'] . ';' . 
                                ' height: ' . $props['size'] . ';">',
        '#suffix' => '</div>',
      );
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/orbital/dls_components.orbital.css';
          
      return $block;
    }
  }