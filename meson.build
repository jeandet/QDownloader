project('QDownloader', 'cpp',default_options : ['cpp_std=c++14'])

qt5 = import('qt5')
qt5core = dependency('qt5', modules : 'Core')
qt5widgets = dependency('qt5', modules : 'Widgets')
qt5svg = dependency('qt5', modules : 'Svg')
qt5xml = dependency('qt5', modules : 'Xml')
qt5network = dependency('qt5', modules : 'Network')
qt5test = dependency('qt5', modules : 'Test')

moc = find_program('moc-qt5','moc')
rcc = find_program('rcc-qt5','rcc')

inc = include_directories('src')

#qdownloader_moc_files = qt5.preprocess(moc_sources : )

qdownloader_lib = library('QDownloader',
                       ['src/QDownloader.cpp', 'src/QDownloaderPrivate.cpp'],
                       include_directories : inc,
                       dependencies : [qt5core, qt5network],
                       install : true
                       )


qdownloader = declare_dependency(link_with : qdownloader_lib,
                                include_directories : inc,
                                dependencies : [qt5core, qt5network])


tests = [
  [['tests/SimpleDownload/simple_download.cpp'], 'SimpleDownload', 'Simple Download']
]


foreach unit_test : tests
  test_moc_files = qt5.preprocess(moc_sources : unit_test[0])
  test_exe = executable(unit_test[1],unit_test[0] , test_moc_files,
                          dependencies : [qdownloader, qt5test])
  test(unit_test[2], test_exe, args: ['-teamcity', '-o', '@0@.teamcity.txt'.format(unit_test[1])])
endforeach
