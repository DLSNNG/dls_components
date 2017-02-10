<?php

  class propType {
    var $types;
    var $required;
    
    function __construct($types, $required = true) {
      $this->types = $types;
      $this->required = $required;
    }
    
    //factory pattern
    static function make($types, $required = true) {
      $propType = new self($types, $required);
      return $propType;
    }
    
    static function String() {
      $propType = new self(array('string'), true);
      return $propType;
    }
    
    static function OptionalString() {
      $propType = new self(array('string'), false);
      return $propType;
    }
    
    static function Number() {
      $propType = new self(array(
        'integer',
        'double'
      ), true);
      return $propType;
    }
    
    static function OptionalNumber() {
      $propType = new self(array(
        'integer',
        'double'
      ), false);
      return $propType;
    }
    
    static function Collection() {
      $propType = new self(array('array'), true);
      return $propType;
    }
    
    static function OptionalCollection() {
      $propType = new self(array('array'), false);
      return $propType;
    }
    
    static function ObjectOfType($type) {
      $propType = new self(array($type), true);
      return $propType;
    }
    
    static function OptionalObjectOfType($type) {
      $propType = new self(array($type), false);
      return $propType;
    }
    
    static function Boolean() {
      $propType = new self(array('boolean'), true);
      return $propType;
    }
    
    static function OptionalBoolean() {
      $propType = new self(array('boolean'), false);
      return $propType;
    }
    
    function getTypes() {
      return implode(', ', $this->types);
    }
    
    function validate($prop) {
      // return true if prop isnt required
      if(!$this->required) { return true; }
      // otherwise check type
      $propType = gettype($prop);
      // if prop is an object, set propType to the class name
      if($propType === 'object') {
        $propType = get_class($prop);
      }
      // if proptype matches return prop
      if(in_array($propType, $this->types)) {
        return true;
      }
      // otherwise return false
      else {
        return false;
      }
    }
  }