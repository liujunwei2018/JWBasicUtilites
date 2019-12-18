#
# Be sure to run `pod lib lint JWBasicUtilites.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'JWBasicUtilites'
  s.version          = '0.1.0'
  s.summary          = 'A short description of JWBasicUtilites.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/liujunwei2018/JWBasicUtilites'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'liujunwei2018' => 'liujunwei0422@icloud.com' }
  s.source           = { :git => 'git@github.com:liujunwei2018/JWBasicUtilites.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'JWBasicUtilites/Classes/**/*'
  
  s.subspec 'Device' do |ss|
    ss.source_files = 'JWBasicUtilites/Classes/Device/**/*.{h,m}'
    ss.public_header_files = 'JWBasicUtilites/Classes/Device/**/*.h'
  end
   s.subspec 'Macros' do |ss|
    ss.source_files = 'JWBasicUtilites/Classes/Macros/**/*.{h,m}'
    ss.public_header_files = 'JWBasicUtilites/Classes/Macros/**/*.h'
  end
  s.subspec 'Runtime' do |ss|
    ss.source_files = 'JWBasicUtilites/Classes/Runtime/**/*.{h,m}'
    ss.public_header_files = 'JWBasicUtilites/Classes/Runtime/**/*.h'
  end
  s.subspec 'UIApplication' do |ss|
    ss.source_files = 'JWBasicUtilites/Classes/UIApplication/**/*.{h,m}'
    ss.public_header_files = 'JWBasicUtilites/Classes/UIApplication/**/*.h'
  end

   s.dependency 'AFNetworking'
end
