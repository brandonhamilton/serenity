/*
 * Copyright (c) 2021, Peter Elliott <pelliott@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/OwnPtr.h>
#include <LibMarkdown/Block.h>
#include <LibMarkdown/ContainerBlock.h>

namespace Markdown {

class BlockQuote final : public Block {
public:
    BlockQuote(OwnPtr<ContainerBlock> contents)
        : m_contents(move(contents))
    {
    }
    virtual ~BlockQuote() override { }

    virtual String render_to_html(bool tight = false) const override;
    virtual String render_for_terminal(size_t view_width = 0) const override;

    static OwnPtr<BlockQuote> parse(LineIterator& lines);

private:
    OwnPtr<ContainerBlock> m_contents;
};

}
