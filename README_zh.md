# stella_vslam_go

[![CI](https://github.com/stella-cv/stella_vslam/actions/workflows/main.yml/badge.svg)](https://github.com/stella-cv/stella_vslam/actions/workflows/main.yml)
[![文档状态](https://readthedocs.org/projects/stella-cv/badge/?version=latest)](https://stella-cv.readthedocs.io/en/latest/?badge=latest)
[![许可证](https://img.shields.io/badge/License-BSD%202--Clause-orange.svg)](https://opensource.org/licenses/BSD-2-Clause)

---

> *注意:* 这是 [xdspacelab/openvslam](https://github.com/xdspacelab/openvslam) 的社区分支。它于2021年1月31日创建，以继续OpenVSLAM的积极开发。原始仓库已不再可用。在使用前，请仔细阅读并理解 [官方终止声明](https://github.com/xdspacelab/openvslam/wiki/Termination-of-the-release)。原始版本中与ORB_SLAM2的相似之处已在 [#252](https://github.com/stella-cv/stella_vslam/pull/252) 中被移除。如果您发现任何其他许可证问题，请指出。请参阅 [#37](https://github.com/stella-cv/stella_vslam/issues/37) 和 [#249](https://github.com/stella-cv/stella_vslam/issues/249) 了解讨论情况。

*早于0.3版本的版本已弃用。如果使用它们，请按照GPL许可证将其作为ORB_SLAM2的衍生产品使用。*

---

## 概述

[<img src="https://raw.githubusercontent.com/stella-cv/docs/main/docs/img/teaser.png" width="640px">](https://arxiv.org/abs/1910.01122)

<img src="https://j.gifs.com/81m1QL.gif" width="640px">

[**[预印本]**](https://arxiv.org/abs/1910.01122)

stella_vslam 是一个单目、双目和RGBD视觉SLAM系统。

### 特性

显著特性包括：

- 兼容 **各种类型的相机模型**，可以轻松自定义其他相机模型。
- 创建的地图可以 **存储和加载**，然后stella_vslam可以基于预建地图对新图像进行 **定位**。
- 系统完全模块化。通过将多个功能封装到具有易于理解API的独立组件中来设计。
- 我们提供了 **一些代码片段** 来理解系统的核心功能。
- **Go语言绑定** - 此分支通过CGO包含Go语言绑定支持。
- **非阻塞导出API** - 添加了线程安全的方法，无需中断跟踪即可导出地图数据库。

stella_vslam的一个值得注意的特性是，该系统可以处理各种类型的相机模型，如透视、鱼眼和等距柱状投影。
如果需要，用户可以轻松实现额外的相机模型（例如，双鱼眼、全向）。
例如，上面显示了使用 **等距柱状投影相机模型**（例如RICOH THETA系列、insta360系列等）的视觉SLAM算法。

我们为安装和教程提供了 [文档](https://stella-cv.readthedocs.io/)。
ROS包装器的仓库是 [stella_vslam_ros](https://github.com/stella-cv/stella_vslam_ros)。

### 致谢

OpenVSLAM基于间接SLAM算法，具有稀疏特征，如 [ORB-SLAM](https://arxiv.org/abs/1502.00956)/[ORB-SLAM2](https://arxiv.org/abs/1610.06475)、[ProSLAM](https://arxiv.org/abs/1709.04377) 和 [UcoSLAM](https://arxiv.org/abs/1902.03729)。
核心架构基于ORB-SLAM/ORB-SLAM2，代码已经重新设计和从头编写，以提高可扩展性、可读性、性能等。
UcoSLAM更早地实现了特征提取、地图存储和加载的并行化。
ProSLAM更早地实现了一个高度模块化且易于理解的系统。

### 示例

提供了一些代码片段来理解系统的核心功能。
您可以将这些片段用于自己的程序中。
请参阅 `./example` 目录中的 `*.cc` 文件或查看 [简单教程](https://stella-cv.readthedocs.io/en/latest/simple_tutorial.html) 和 [示例](https://stella-cv.readthedocs.io/en/latest/example.html)。

## 安装

请参阅 [文档](https://stella-cv.readthedocs.io/) 中的 [**安装**](https://stella-cv.readthedocs.io/en/latest/installation.html) 章节。

也提供了 [**Docker用户的说明**](https://stella-cv.readthedocs.io/en/latest/docker.html)。

## 教程

请参阅 [文档](https://stella-cv.readthedocs.io/) 中的 [**简单教程**](https://stella-cv.readthedocs.io/en/latest/simple_tutorial.html) 章节。

可以从 [这里](https://github.com/stella-cv/FBoW_orb_vocab/raw/main/orb_vocab.fbow) 下载样本ORB词汇文件。
示例数据集也在 [这里](https://drive.google.com/open?id=1A_gq8LYuENePhNHsuscLZQPhbJJwzAq4) 提供。

如果您想使用标准基准数据集（例如KITTI里程计数据集）运行视觉SLAM，请参阅 [文档](https://stella-cv.readthedocs.io/) 中的 [**标准数据集上的SLAM**](https://stella-cv.readthedocs.io/en/latest/example.html#slam-with-standard-datasets) 部分。

## 社区

如果您对软件有任何问题或注意到任何错误，请通过 [GitHub Discussions](https://github.com/stella-cv/stella_vslam/discussions) 联系我们。

## 当前工作

- 重构
- 算法更改和参数添加以提高性能
- 添加测试
- 标记集成
- 实现额外的相机模型
- Python绑定
- IMU集成
- Go绑定和非阻塞导出API（在此分支中添加）

列表越靠上，优先级越高。
欢迎反馈、功能请求和贡献！

## Go绑定和非阻塞导出

此stella_vslam分支通过CGO添加了Go语言绑定支持。主要新增内容包括：

- **非阻塞导出API**：新的方法可在不阻塞跟踪过程的情况下将地图数据库导出到内存字节：
  - `export_map_database_bytes()` - 将当前地图数据库导出到内存中的msgpack字节
  - `pause_map_update()` - 暂停LocalMapping和LoopClosing线程
  - `resume_map_update()` - 恢复LocalMapping和LoopClosing线程

- **Go集成**：该功能设计用于与使用CGO与C++代码接口的“vslam-daemon”包装器一起工作。

要使用Go支持编译，请使用编译标志 `STELLA_VSLAM_NONBLOCKING_EXPORT`，如NONBLOCKING_EXPORT.md文件中所述。

## 许可证

**2-clause BSD license** (见 [LICENSE](./LICENSE))

以下文件来自第三方库。

- `./3rd/json` : [nlohmann/json \[v3.6.1\]](https://github.com/nlohmann/json) (MIT license)
- `./3rd/spdlog` : [gabime/spdlog \[v1.3.1\]](https://github.com/gabime/spdlog) (MIT license)
- `./3rd/tinycolormap` : [yuki-koyama/tinycolormap](https://github.com/yuki-koyama/tinycolormap) (MIT license)
- `./3rd/FBoW` : [stella-cv/FBoW](https://github.com/stella-cv/FBoW) (MIT license) (forked from [rmsalinas/fbow](https://github.com/rmsalinas/fbow))
- `./src/stella_vslam/solver/essential_5pt.h` : part of [libmv/libmv](https://github.com/libmv/libmv) (MIT license)
- `./src/stella_vslam/solver/pnp_solver.cc` : part of [laurentkneip/opengv](https://github.com/laurentkneip/opengv) (3-clause BSD license)
- `./src/stella_vslam/feature/orb_extractor.cc` : part of [opencv/opencv](https://github.com/opencv/opencv) (3-clause BSD License)
- `./src/stella_vslam/feature/orb_point_pairs.h` : part of [opencv/opencv](https://github.com/opencv/opencv) (3-clause BSD License)

请使用`g2o`作为动态链接库，因为`g2o`的`csparse_extension`模块是LGPLv3+。

## 原始OpenVSLAM版本的作者

- Shinya Sumikura ([@shinsumicco](https://github.com/shinsumicco))
- Mikiya Shibuya ([@MikiyaShibuya](https://github.com/MikiyaShibuya))
- Ken Sakurada ([@kensakurada](https://github.com/kensakurada))

## 引用原始OpenVSLAM版本

OpenVSLAM **在ACM多媒体2019开源软件竞赛中获得第一名**。

如果OpenVSLAM帮助了您的研究，请引用OpenVSLAM的论文。这是BibTeX条目：

```
@inproceedings{openvslam2019,
  author = {Sumikura, Shinya and Shibuya, Mikiya and Sakurada, Ken},
  title = {{OpenVSLAM: A Versatile Visual SLAM Framework}},
  booktitle = {Proceedings of the 27th ACM International Conference on Multimedia},
  series = {MM '19},
  year = {2019},
  isbn = {978-1-4503-6889-6},
  location = {Nice, France},
  pages = {2292--2295},
  numpages = {4},
  url = {http://doi.acm.org/10.1145/3343031.3350539},
  doi = {10.1145/3343031.3350539},
  acmid = {3350539},
  publisher = {ACM},
  address = {New York, NY, USA}
}
```

预印本可在 [这里](https://arxiv.org/abs/1910.01122) 找到。

## 参考文献

- Raúl Mur-Artal, J. M. M. Montiel, and Juan D. Tardós. 2015. ORB-SLAM: a Versatile and Accurate Monocular SLAM System. IEEE Transactions on Robotics 31, 5 (2015), 1147–1163.
- Raúl Mur-Artal and Juan D. Tardós. 2017. ORB-SLAM2: an Open-Source SLAM System for Monocular, Stereo and RGB-D Cameras. IEEE Transactions on Robotics 33, 5 (2017), 1255–1262.
- Dominik Schlegel, Mirco Colosi, and Giorgio Grisetti. 2018. ProSLAM: Graph SLAM from a Programmer's Perspective. In Proceedings of IEEE International Conference on Robotics and Automation (ICRA). 1–9.
- Rafael Muñoz-Salinas and Rafael Medina Carnicer. 2019. UcoSLAM: Simultaneous Localization and Mapping by Fusion of KeyPoints and Squared Planar Markers. arXiv:1902.03729.
- Mapillary AB. 2019. OpenSfM. <https://github.com/mapillary/OpenSfM>.
- Giorgio Grisetti, Rainer Kümmerle, Cyrill Stachniss, and Wolfram Burgard. 2010. A Tutorial on Graph-Based SLAM. IEEE Transactions on Intelligent Transportation SystemsMagazine 2, 4 (2010), 31–43.
- Rainer Kümmerle, Giorgio Grisetti, Hauke Strasdat, Kurt Konolige, and Wolfram Burgard. 2011. g2o: A general framework for graph optimization. In Proceedings of IEEE International Conference on Robotics and Automation (ICRA). 3607–3613.