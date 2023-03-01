project('password-random-generator', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

inc = include_directories('include')

#subdir('include')
#subdir('src')

gtkDep = dependency('gtk4')
sqliteDep = dependency('sqlite3')

exe = executable('password_random_generator', ['src/password_random_generator.c','src/db/db.c'],
  install : true,
  dependencies : [gtkDep, sqliteDep],
  include_directories : inc)

test('basic', exe)
