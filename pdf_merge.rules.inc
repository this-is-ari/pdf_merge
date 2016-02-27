<?php

/**
 * @file
 *   Provides integration with Rules module.
 */

/**
 * Implement hook_rules_action_info().
 */
function pdf_merge_rules_action_info() {
  return array(
    'pdf_merge_rules_action' => array(
      'label' => t('Merge PDF files'),
      'group' => t('PDF'),
      'parameter' => array(
        'entity_objects' => array(
          'type' => 'list<file>',
          'label' => t('PDF file entities to merge'),
          'description' => t('Select the list of PDF file entities to merge.'),
        ),
      ),
      'provides' => array(
        'merged_pdf' => array(
          'type' => 'file',
          'label' => t('Merged PDF File'),
        ),
      ),
    ),
  );
}

/**
 * Implements Rule's Action.
 *
 * Builds a list of PDF files attached to 'Document' entities and
 * send this list to pdf_merge_multiple().
 *
 * @param array $entity_id_list
 *   List of entities of 'document' type.
 */
function pdf_merge_rules_action($entity_objects) {
  // Get list of fid of related PDF files.
  foreach ($entity_objects as $entity) {
    $fids[] = $entity->fid;
  }
  
  $file = pdf_merge_multiple($fids);
  $result = ($file != FALSE) ? array('merged_pdf' => $file) : FALSE;
  return $result;
}
