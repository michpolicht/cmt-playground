# Libraries directory

This directory keeps the source code of arbitrary collection of libraries.

The directory itself is called `lib` for easier integration with tools such as
AppImage.

Individual library projects can be put into subdirectories. Most commonly
subdirectory would group libraries from a specific vendor. This makes it easier
to create source code antologies or collections with git subtree as it only
requires to specify a single prefix for entire collection of libraries from
specific external repository.

## Naming conventions

Library names are composed of name parts separated by hyphens. Typically, first
part is the name of the vendor and the last part is the major version number.

If library project is put into subdirectory it is highly recommended to reflect
the parts of the library name in the hierarchy of subdirectories to keep project
organization clean and avoid naming conflicts.

Name parts should be also reflected on the source code level. Especially C++
namespaces should follow the library name scheme.

