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
