<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');

  class div extends dcomponent {
    var $propTypes = array(
      'text' => 'string',  
      'class' => 'string',
    );
    
    function render() {
    	$block = array(
    	  '#type' => 'markup',
    	  '#markup' => $this->props['text'],
    	  '#prefix' => '<div class="' . $this->props['class'] . '">',
    	  '#suffix' => '</div>',
    	);
    	return $block;
    }
  }