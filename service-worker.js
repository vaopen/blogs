/**
 * Welcome to your Workbox-powered service worker!
 *
 * You'll need to register this file in your web app and you should
 * disable HTTP caching for this file too.
 * See https://goo.gl/nhQhGp
 *
 * The rest of the code is auto-generated. Please don't update this file
 * directly; instead, make changes to your Workbox build configuration
 * and re-run your build process.
 * See https://goo.gl/2aRDsh
 */

importScripts("https://storage.googleapis.com/workbox-cdn/releases/4.3.1/workbox-sw.js");

self.addEventListener('message', (event) => {
  if (event.data && event.data.type === 'SKIP_WAITING') {
    self.skipWaiting();
  }
});

/**
 * The workboxSW.precacheAndRoute() method efficiently caches and responds to
 * requests for URLs in the manifest.
 * See https://goo.gl/S9QRab
 */
self.__precacheManifest = [
  {
    "url": "404.html",
    "revision": "6728c9ec694d4c4810a0165bc521e570"
  },
  {
    "url": "About.html",
    "revision": "99eec36398cb14dcf632df770e1c4a3d"
  },
  {
    "url": "assets/css/0.styles.57c051fb.css",
    "revision": "e1d3884924e7e201859ae9c350a67114"
  },
  {
    "url": "assets/img/home-bg.7b267d7c.jpg",
    "revision": "7b267d7ce30257a197aeeb29f365065b"
  },
  {
    "url": "assets/img/home-head.9e98f9ef.png",
    "revision": "9e98f9efba10bcad33519b782a1d09db"
  },
  {
    "url": "assets/img/icon_vuepress_reco.406370f8.png",
    "revision": "406370f8f120332c7a41611803a290b6"
  },
  {
    "url": "assets/img/search.83621669.svg",
    "revision": "83621669651b9a3d4bf64d1a670ad856"
  },
  {
    "url": "assets/js/1.94aa9c18.js",
    "revision": "c752fc409d945e5454b95b0ab4d83693"
  },
  {
    "url": "assets/js/10.da08dcec.js",
    "revision": "c609d555a89a4cc093f26f93eff68330"
  },
  {
    "url": "assets/js/11.e5029f54.js",
    "revision": "5744680dbb8ebec04abcb18928aae3d1"
  },
  {
    "url": "assets/js/12.ed3068a9.js",
    "revision": "34a1ac500bf4cbb73fc054b057e19919"
  },
  {
    "url": "assets/js/13.d3a9b883.js",
    "revision": "c21c75ad39f65928ef021298c9e8fe70"
  },
  {
    "url": "assets/js/14.097d0054.js",
    "revision": "4aa4ee8d332266ade7fbc2def862aa58"
  },
  {
    "url": "assets/js/15.5dc52d50.js",
    "revision": "163d2bff47a840215175143d4a3eb1f4"
  },
  {
    "url": "assets/js/4.59a3cdd3.js",
    "revision": "46c9adb7db5d6eb64fd4b490160e0165"
  },
  {
    "url": "assets/js/5.b4403148.js",
    "revision": "70c578f669e2ad58ebeea63b94f4b7c1"
  },
  {
    "url": "assets/js/6.a9f4fd72.js",
    "revision": "d306195e31a0f44f27dddd94cda97fe6"
  },
  {
    "url": "assets/js/7.613115aa.js",
    "revision": "f64f39ab8b57febb58342fe6c367ae25"
  },
  {
    "url": "assets/js/8.f443fdc5.js",
    "revision": "8e6a20e158d3971db2eb71a4cab13616"
  },
  {
    "url": "assets/js/9.3046f8a3.js",
    "revision": "c718d6481d5a4e88d61d2e08c4a993df"
  },
  {
    "url": "assets/js/app.37ccca1e.js",
    "revision": "e70bfcc94a47b7897c7b88ca43229638"
  },
  {
    "url": "assets/js/vendors~flowchart.14050ee4.js",
    "revision": "1a53fce8e18439692adfd858eb954594"
  },
  {
    "url": "avatar.jpg",
    "revision": "053d7743ab23f7141a692ab1c5c56886"
  },
  {
    "url": "categories/Electron/index.html",
    "revision": "33d01e071a25d6139b27131a8fdacb53"
  },
  {
    "url": "categories/index.html",
    "revision": "6d5347f77c13eae15b4d2b3db3a84361"
  },
  {
    "url": "hero.png",
    "revision": "5367b9349d4e048235eeed50d9ef36df"
  },
  {
    "url": "index.html",
    "revision": "b1560a9b98919523ad7cad5059a7ebc2"
  },
  {
    "url": "tag/index.html",
    "revision": "d04a805550ad03fc3040fba32897d9b8"
  },
  {
    "url": "tags/javaScript/index.html",
    "revision": "fa545ba39ac5c8199f98125f99f6280a"
  },
  {
    "url": "tags/日常错误问题收集/index.html",
    "revision": "b9de045a0180c0f49c75ce7b8f364588"
  },
  {
    "url": "timeline/index.html",
    "revision": "e60684ba7a3ac8c60ccd1881c414a960"
  },
  {
    "url": "views/2020/Electron-win7-black-screen.html",
    "revision": "10cabb8ac74d8bdaf802cc359d9c0b75"
  }
].concat(self.__precacheManifest || []);
workbox.precaching.precacheAndRoute(self.__precacheManifest, {});
addEventListener('message', event => {
  const replyPort = event.ports[0]
  const message = event.data
  if (replyPort && message && message.type === 'skip-waiting') {
    event.waitUntil(
      self.skipWaiting().then(
        () => replyPort.postMessage({ error: null }),
        error => replyPort.postMessage({ error })
      )
    )
  }
})
