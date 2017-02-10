<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class linklistItem extends dcomponent {
    function propTypes() {
      return array(
        'text' => propType::String(),  
        'class' => propType::String(),
        'url' => propType::String(),
      );
    }
    
    function render() {
        $props = $this->props;
    	$block = array(
    	  '#type' => 'markup',
    	  '#markup' => $props['text'],
    	  '#prefix' => '<a href="' . $props['url'] . '"><li class="' . $props['class'] . '">',
    	  '#suffix' => '</li></a>',
    	);
    	return $block;
    }
  }