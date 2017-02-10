<?php

  class errorTracker {
 		var $errors = array();

 		function addError($errorText) {
 			$this->errors[] = $errorText;
 		}

 		function renderErrors() {
 		  $errors = array(
 		    '#type' => 'markup',
 		    '#prefix' => '<script>',
 		    '#suffix' => '</script>',
 		  );
 			foreach($this->errors as $error) {
 				$errors[] = array(
 				  '#type' => 'markup',
 				  '#markup' => $error,
 				  '#prefix' => 'console.log("',
 				  '#suffix' => '");',
 				);
 			}
 			return $errors;
 		}
 	}