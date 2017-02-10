<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class listItem extends dcomponent {
    function propTypes() {
      return array(
        'text' => propType::String(),  
        'class' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $class = isset($props['class']) ? $props['class'] : '';
    	$block = array(
    	  '#type' => 'markup',
    	  '#markup' => $this->props['text'],
    	  '#prefix' => '<li class="' . $class . '">',
    	  '#suffix' => '</l>',
    	);
    	return $block;
    }
  }