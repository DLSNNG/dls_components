<?php

  // base class
  class dcontroller {
    
    public $model;
    protected $allowedActions = array();
    protected $target;
    
    
    public function __construct($model) {
      $this->model = $model;
      //set default target to current path
      $this->target = url(current_path(), array('absolute' => TRUE));
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
        $this->goToTarget();
      }
    }
    
    // set value of $this->target in action to change location
    protected function goToTarget() {
      $state = $this->model->state;
      unset($state['action']);
      drupal_goto($this->target, array('query' => $state));
    }
    
    // helper method for retreiving model state
    protected function getState() {
      return $this->model->state;
    }
    
    // helper method for setting model state
    protected function setState($state) {
      $this->model->state = $state;
    }
    
    //use factory pattern so we dont have to new-up/render each controller manually in our markup
    public static function make($model) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $controller = new static($model);
      return $controller;
    }
    
  }