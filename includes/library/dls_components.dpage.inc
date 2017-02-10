<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dmodel');

  class dpage {
    private $model;
    private $view;
    private $controller;
    
    public function __construct($componentName, $controllerName) {
      $this->model = dmodel::make(array('text' => 'testing', 'name' => 'testname'));
      $this->controller = new $controllerName($this->model);
      $this->view = new $componentName($this->model->props);
    }
    
    //use factory pattern so we dont have to new-up/render each model manually in our markup
    public static function make($componentName, $controllerName) {
      
      //use static() instead of self() to return the inheriting class instead of this base class.
      $page = new static($componentName, $controllerName);
      return $page->composePage();
    }
    
    private function composePage() {
      return $this->view->render();
    }
  }