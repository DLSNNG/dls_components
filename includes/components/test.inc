<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  module_load_include('inc', 'dls_components', '/includes/components/test2');

  class test extends dcomponent {
    function propTypes() {
      return array(
        'test1' => propType::String(),
      );
    }
    
    function render() {
    	$block = array(
    	  '#type' => 'markup',
    	  'test2' => test2::make(array('text' => 'testing')),
    	  'test2 again' => test2::make(array('text' => 'to see if it works')),
    	  '#prefix' => '<div>',
    	  '#suffix' => '</div>',
    	);
    	return $block;
    }
  }