<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  module_load_include('inc', 'dls_components', '/includes/components/orbital/dls_components.orbital_item');
  

  class Orbital extends dcomponent {
    function propTypes() {
      return array(
        'items' => propType::Collection(),
        'size' => propType::String(),
        'class' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      
      $items = $props['items'];
      $class = isset($props['class']) ? 'orbital ' . $props['class'] : 'orbital';
      
      
      $block = array(
        '#type' => 'markup',
        'center' => array(
          '#type' => 'markup',
          '#markup' => '<i class="fa fa-search"></i>',
          '#prefix' => '<div class="center">',
          '#suffix' => '</div>',
        ),
        '#prefix' => '<div class="' . $class . '"' .
                          'style="width: ' . $props['size'] . ';' . 
                                ' height: ' . $props['size'] . ';">',
        '#suffix' => '</div>',
      );
      
      for($i=0; $i<count($items); $i++) {
        $rotate = $i * 360/count($items);
        $block[] = OrbitalItem::make(array(
          'size' => $props['size'],
          'rotate' => $rotate . 'deg',
          'contents' => $props['items'][$i],
        ));
      }
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/orbital/dls_components.orbital.css';
          
      return $block;
    }
  }