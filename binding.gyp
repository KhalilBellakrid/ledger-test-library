{
  'targets': [
      {
      'target_name': 'ledgerapp_nodejs',
      'sources': [
      		'nodejs/ledgerapp_module.cpp',
      		'nodejs/NJSHttpModule.cpp',
      		'nodejs/NJSHttpModule.h',
      		'nodejs/NJSCallbackModule.cpp',
      		'nodejs/NJSCallbackModule.h',
      		'nodejs/NJSApi.cpp',
      		'nodejs/NJSApi.h',
      		'nodejs/NJSThreadDispatcher.cpp',
      		'nodejs/NJSThreadDispatcher.h',
		'nodejs/NJSExecutionContext.cpp',
      		'nodejs/NJSExecutionContext.h',
      		'nodejs/NJSTransactionListVmObserver.cpp',
      		'nodejs/NJSTransactionListVmObserver.h',
      		'nodejs/NJSLock.cpp',
      		'nodejs/NJSLock.h'
       ],
       'include_dirs': [
			"<!(node -e \"require('nan')\")"
        ],
		  'all_dependent_settings': {
			'include_dirs': [
				"<!(node -e \"require('nan')\")"
			],
		},
		'dependencies': [
                'ledgerapp.gyp:libledgerapp',
         ],
      'conditions': [
        [ 'OS=="mac"', {
              'LDFLAGS': [
            '-framework IOKit',
            '-framework CoreFoundation'
          ],
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'OTHER_CFLAGS': [
              '-ObjC++',
              '-std=c++14',
            ],
            'OTHER_LDFLAGS': [
              '-framework IOKit',
              '-framework CoreFoundation'
            ],
          },
        }],
        [ 'OS=="win"', {
			'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
			'OTHER_CFLAGS': [
			  '-std=c++14',
			]
       	 }]
      ],
      'cflags!': ['-ansi', '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'cflags': ['-g', '-exceptions'],
      'cflags_cc': ['-g', '-exceptions']
    }
  ]
}
