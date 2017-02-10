<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class element extends dcomponent {
    function propTypes() {
      return array(
        'type' => propType::String(),
        'text' => propType::String(),  
        'class' => propType::OptionalString(),
      );
    }
    
    function render() {
      $class = isset($this->props['class']) ? $this->props['class'] : '';
    	$block = array(
    	  '#type' => 'markup',
    	  '#markup' => $this->props['text'],
    	  '#prefix' => '<' . $this->props['type'] . ' class="' . $class . '">',
    	  '#suffix' => '</' . $this->props['type']  . '>',
    	);
    	return $block;
    }
  }