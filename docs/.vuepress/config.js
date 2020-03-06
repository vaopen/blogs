module.exports = {
  base: '/blogs/',
  title: "vaopen'blog",
  description: "不能因理想遥远而放弃追求 不能因现实复杂而放弃梦想",
  evergreen: true,
  locales: {
    "/": {
      lang: "zh-CN"
    }
  },
  head: [
    [
      "meta",
      {
        name: "viewport",
        content: "width=device-width,initial-scale=1,user-scalable=no"
      }
    ],
    [
      "link",
      {
        rel: "stylesheet",
        href: "https://cdn.jsdelivr.net/npm/katex@0.11.1/dist/katex.min.css"
      }
    ],
    ["meta", { name: "theme-color", content: "#222222" }],
    ["meta", { name: "apple-mobile-web-app-capable", content: "yes" }],
    [
      "meta",
      { name: "apple-mobile-web-app-status-bar-style", content: "black" }
    ],
    ["meta", { name: "msapplication-TileColor", content: "#000000" }]
  ],

  markdown: {
    // 代码显示行号
    lineNumbers: true,
    // markdown-it-anchor 的选项
    anchor: { permalink: true },
    // markdown-it-toc 的选项
    toc: { includeLevel: [1, 2, 3] },
    // markdown 插件
    extendMarkdown: md => {
      md.set({ html: true });
      md.use(require("@iktakahiro/markdown-it-katex"));
      md.use(require("markdown-it-mark"));
      md.use(require("markdown-it-task-lists"));
      md.use(require("markdown-it-vuepress-code-snippet-enhanced"));
    }
  },

  // 插件
  plugins: [
    // 开启 PWA
    [
      "@vuepress/pwa",
      {
        serviceWorker: true,
        updatePopup: true
      }
    ],
    // 彩带背景
    [
      "ribbon",
      {
        size: 90,
        opacity: 0.8,
        zIndex: -1
      }
    ],
    // 鼠标特效插件
    [
      "cursor-effects",
      {
        shape: "star"
      }
    ],
    // 离开页面标题变化
    [
      "dynamic-title",
      {
        showIcon: "/favicon.ico",
        showText: "(ฅ>ω<*ฅ)欢迎回来！",
        hideIcon: "/failure.ico",
        hideText: "( ๑ˊ•̥▵•)੭₎₎不要走呀！",
        recoverTime: 2000
      }
    ],
    // 悬挂小猫返回顶部
    ["go-top"],
    // 禁用无用插件
    ["@vuepress-reco/back-to-top", false],
    ["@vuepress-reco/extract-code", false],
    // 流程图
    ["flowchart"],
  ],

  // 主题配置
  theme: "reco",
  themeConfig: {
    // 博客配置
    type: "blog",
    logo: "/avatar.jpg",
    autoHideNavbar: true,
    blogConfig: {
      category: {
        location: 2, // 在导航栏菜单中所占的位置，默认2
        text: "Category" // 默认文案 “分类”
      },
      tag: {
        location: 3, // 在导航栏菜单中所占的位置，默认3
        text: "Tag" // 默认文案 “标签”
      }
    },
    author: "vaopen",
    // 备案号
    // record: "辽ICP备19014250号-1",
    // 项目开始时间，只填写年份
    startYear: "2020",
    nav: [
      { text: "Home", link: "/", icon: "reco-home" },
      { text: "TimeLine", link: "/TimeLine/", icon: "reco-date" },
      { text: "About", link: "/About.html", icon: "reco-account" },
      {
        text: "Contact",
        icon: "reco-message",
        items: [
          {
            text: "Github",
            link: "https://github.com/blacklisten",
            icon: "reco-github"
          }
        ]
      }
    ],
    friendLink: [],
    sidebarDepth: 1,
    sidebar: "auto",
    vssueConfig: {
      platform: "github",
      owner: "vaopen",
      repo: "vaopen.github.io",
      clientId: "5bae6136e7b844971fec",
      clientSecret: "0be03091452ca01fc5ab0ed7b7346e671dc2c7d0"
    },

    lastUpdated: "Last Updated", // string | boolean

    // 假定是 GitHub. 同时也可以是一个完整的 GitLab URL
    // repo: "SigureMo/notev",
    // 自定义仓库链接文字。默认从 `themeConfig.repo` 中自动推断为
    // "GitHub"/"GitLab"/"Bitbucket" 其中之一，或是 "Source"。
    // repoLabel: "Repo",

    // 以下为可选的编辑链接选项

    // 假如你的文档仓库和项目本身不在一个仓库：
    docsRepo: "SigureMo/notev",
    // 假如文档不是放在仓库的根目录下：
    docsDir: "docs",
    // 假如文档放在一个特定的分支下：
    docsBranch: "master",
    // 默认是 false, 设置为 true 来启用
    editLinks: true,
    // 默认为 "Edit this page"
    editLinkText: "在GitHub上编辑此页！",
    // Service Worker 的配置
    serviceWorker: {
      updatePopup: true
    }
  }
};
