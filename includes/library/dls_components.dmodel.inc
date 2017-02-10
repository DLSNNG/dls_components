<?php

  class dmodel {
    
    public $state;
    public $props;
    
    public function __construct($startingProps = array()) {
      $this->props = $startingProps;
      $this->state = drupal_get_query_parameters();
    }
    
    //use factory pattern so we dont have to new-up/render each model manually in our markup
    public static function make($startingProps = array()) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $model = new static($startingProps);
      return $model;
    }
    
  }