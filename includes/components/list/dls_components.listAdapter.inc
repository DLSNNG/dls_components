<?php

  class ListAdapter {
    
    public function __construct($arrayMap) {
      $this->map = $arrayMap;
    }
    
    public function map($object) {
      $props = array();
      
      foreach($this->map as $propName => $objectKey) {
        $props[$propName] = $object->$objectKey;
      }
      
      return $props;
    }
    
    //use factory pattern so we dont have to new-up/render each model manually in our markup
    public static function make($arrayMap) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $adapter = new static($arrayMap);
      return $adapter;
    }
    
  }