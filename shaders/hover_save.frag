#version 120
uniform sampler2D texture;

void main()
{
    vec2 uv = gl_TexCoord[0].st;
    vec4 text = texture2D(texture, uv);

    text.rgb += 0.2;
    gl_FragColor = vec4(text.rgba);
}
