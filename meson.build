project('password-random-generator', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

gtkDep = dependency('gtk4')
sqliteDep = dependency('sqlite3')

exe = executable('password_random_generator', 'src/password_random_generator.c',
  install : true,
  dependencies : [gtkDep, sqliteDep])

test('basic', exe)
