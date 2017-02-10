<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class FontAwesomeIcon extends dcomponent {
    function propTypes() {
      return array(
        'iconType' => propType::String(),
        'className' => propType::OptionalString(),
        'url' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $iconType = $props['iconType'] ? $props['iconType'] : '';
      $className = $props['className'] ? $props['className'] : '';
      
      $block = array(
        '#type' => 'markup',
        '#markup' => '<i class="fa ' . $iconType . ' icon ' . $className . 
                        '" aria-hidden="true"></i>',
      );
      
      if(isset($props['url'])) {
        $block['#prefix'] = '<a href="' . $props['url'] . '">';
        $block['#suffix'] = '</a>';
      }
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/theme/css/font-awesome.min.css';
          
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/icon/dls_components.font_awesome_icon.css';
      
      return $block;
    }
  }