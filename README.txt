PDF Merge module for Drupal 7.x
-------------------------------

This module allows to merge unlimited number of PDF files into single one.

Installation
------------

1. Download and install PDFtk library from http://pdftk.com.
2. Install PDF Merge module.


Usage
-----

Using Drupal UI
===============

1. Open Content/Files (admin/content/file) page.
2. Upload several PDF-files or select existing.
   Note: Selected non PDF files will be ignored.
3. In 'Update options' select 'Merge PDF file' and press 'Update'.

Expected result: New PDF file will be shown in the list.


Using Rules Link module.
========================

Preparations:
1. Install Rules Link module.
2. Install File Entity module.
3. Create new custom entity and name it 'document'.
4. Add field 'field_pdf_file' to 'document' entity.
5. Create new entity 'project'.
6. Link project and document entities using referrence.
7. Create a view (with VBO).
8. Create new rule link at admin/config/workflow/rules_links.
9. Attach this link to 'project' entity.
10. Add new rule action: Load entity id list (VBO).
11. Add new rule action: Merge PDF files.
12. Select 'entity_id_list' as a value.

Test:
1. Create a test project and attach several PDF files to it.
2. Click rules link.
3. Check if merged file appears at admin/content/file.


Using Rules Component
========================
Import the following component to demonstrate the functionality:

{ "rules_test_pdf_form_merging" : {
    "LABEL" : "Test PDF Form Merging",
    "PLUGIN" : "rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "pdf_merge" ],
    "USES VARIABLES" : {
      "file1" : { "label" : "File1", "type" : "file" },
      "file2" : { "label" : "File2", "type" : "file" },
      "merged_file" : { "label" : "Merged File", "type" : "file", "parameter" : false }
    },
    "DO" : [
      { "variable_add" : {
          "USING" : { "type" : "list\u003Cfile\u003E", "value" : [ "" ] },
          "PROVIDE" : { "variable_added" : { "list_of_file_items" : "list of file items" } }
        }
      },
      { "list_add" : {
          "list" : [ "list-of-file-items" ],
          "item" : [ "file1" ],
          "unique" : "1"
        }
      },
      { "list_add" : {
          "list" : [ "list-of-file-items" ],
          "item" : [ "file2" ],
          "unique" : "1"
        }
      },
      { "pdf_merge_rules_action" : {
          "USING" : { "entity_objects" : [ "list-of-file-items" ] },
          "PROVIDE" : { "merged_pdf" : { "merged_pdf" : "Merged PDF File" } }
        }
      },
      { "data_set" : { "data" : [ "merged-file" ], "value" : [ "merged-pdf" ] } }
    ],
    "PROVIDES VARIABLES" : [ "merged_file" ]
  }
}