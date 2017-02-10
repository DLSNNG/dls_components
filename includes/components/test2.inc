<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');

  class test2 extends dcomponent {
    var $propTypes = array(
      'text' => 'string',  
    );
    
    function render() {
    	$block = array(
    	  '#type' => 'markup',
    	  '#markup' => $this->props['text'],
    	  '#prefix' => '<h1 class="test2">',
    	  '#suffix' => '</h1>',
    	);
    	return $block;
    }
  }