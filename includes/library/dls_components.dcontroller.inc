<?php

  // base class
  class dcontroller {
    
    public $model;
    protected $allowedActions = array();
    
    
    public function __construct($model) {
      $this->model = $model;
      $this->onInit();
      $this->handleAction();
    }
    
    
    // override in child class
    protected function onInit() {}
    
    protected function handleAction() {
      $action = isset($this->model->state['action']) ? $this->model->state['action'] : false;
      if($action && in_array($action, $this->allowedActions)) {
        unset($this->model->state['action']); // remove to prevent looping
        $this->$action(); // actions to be implemented by child class
      }
    }
    
    //use factory pattern so we dont have to new-up/render each controller manually in our markup
    public static function make($model) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $controller = new static($model);
      return $controller;
    }
    
  }