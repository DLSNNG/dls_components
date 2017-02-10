<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.errorTracker');
  module_load_include('inc', 'dls_components', '/includes/library/propTypes/dls_components.propTypes');
  
	class dcomponent extends errorTracker {
	  
	  //TODO: Add styles property to this, for component specific styles
	  
	  
    var $props = array();
    
    function __construct($props) {
      
      $this->validateProps($props);
    }
    
    function _render() {
      
      //if we have errors, show the errors
      if(count($this->errors) > 0) {
        return $this->renderErrors();
      }
      //otherwise render the component
      else {
        return $this->render();
      }
    }
    
    //use factory pattern so we dont have to new-up/render each component manually in our markup
    public static function make($props) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $component = new static($props);
      return $component->_render();
    }
  
    //implemented by the child class
    function propTypes() {}
  
    //implemented by the child class
    function render() {}
    
    //check to make sure all props match expected prop types
    //and generate error if they dont.
    function validateProps($props) {
      
      foreach($this->propTypes() as $name => $propType) {
        if(array_key_exists($name, $props)) {
          $prop = $props[$name];
          $missing = false;
        }
        else {
          $missing = true;
        }
        if($missing) {
          if($propType->required) {
            $this->addError('Missing value for prop [' . $name . '] in component [' . get_class($this). '].');
          }
          continue; //but don't add blank prop
        }
        $validProp = $propType->validate($prop);
        if($validProp) {
          $this->props[$name] = $prop;
        }
        else {
          $this->addError('Invalid prop type supplied to prop [' . $name . '] in component [' . 
                            get_class($this) . ']. Received [' .
                            $prop . ']. Expected [' . $propType->getTypes() . '].');
        }
      }
    }
  }