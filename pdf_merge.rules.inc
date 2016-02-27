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
      'group' => t('PDF Forms'),
      'parameter' => array(
        'entity_id_list' => array(
          'type' => 'list<integer>',
          'label' => t('PDF files to merge'),
          'description' => t('Select the list of PDF files to merge. Hold [Ctrl] to select multiple roles.'),
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
function pdf_merge_rules_action($entity_id_list) {
  // Get list of fid of related PDF files.
  $documents = entity_load('document', $entity_id_list);
  $fids = array();
  foreach ($documents as $doc) {
    //@todo Avoid hardcoded field name.
    $fids[] = $doc->field_pdf_file[LANGUAGE_NONE][0]['fid'];
  }
  pdf_merge_multiple($fids);
}
